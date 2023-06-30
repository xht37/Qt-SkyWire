#include "widget.h"
#include "add_map.h"
  #include <QThread>

const qreal gravity = 0.0002;
const qreal miu = 0.3;

Widget::Widget(QWidget *parent): QWidget(parent),life(3)
{
    setFixedSize(1001, 901);

    time.start();
    // 创建定时器
    timer = new QTimer(this);
    Muteki = new QTimer(this);
    Wait = new QTimer(this);
    Muteki->setSingleShot(true);
    connect(timer, &QTimer::timeout, this, &Widget::updatePosition);
    timer->start(20); // 更新间隔时间

    // 初始化路径和参数
    addPath(path);
    addTrap(tp);
    t = 0.0;
    speed = 0.0;
    connect(timer, &QTimer::timeout, this, &Widget::updateSpeed);
    QPointF point = path.pointAtPercent(t);

    // 别急，先等个1秒半
    Wait->start(1500);
    Wait->setSingleShot(true);

    // 准备bgm
    QMediaPlayer* ready_music = new QMediaPlayer(this);
    ready_music->setMedia(QUrl::fromLocalFile("Starlight.mp3"));
    ready_music->setVolume(40);
    ready_music->play();
    QTimer::singleShot(1800, ready_music, &QMediaPlayer::stop);
    // 保存开场音效，方便delete
    am.push_back(ready_music);


    // 播放bgm
    bgm = new QMediaPlayer(this);
    bgm->setMedia(QUrl::fromLocalFile("Devil may cry.mp3"));
    bgm->setVolume(40);
    QTimer::singleShot(1500, bgm, &QMediaPlayer::play);

    // 上车动画
    QLabel* label_up = new QLabel(this);
    QMovie* movie_up = new QMovie("geton.gif");
    movie_up->setSpeed(300);
    label_up->setMovie(movie_up);
    movie_up->start();
    label_up->move(point.x()-2.5-movie_up->frameRect().width()/2,point.y());
    label_up->show();
    QTimer::singleShot(1500, label_up, &QLabel::hide);

    // other 拼凑出的伪背景
    earth = new QLabel(this);
    QPixmap pixbg("earth.png");
    earth->setPixmap(pixbg);
    earth->move(0,0);
    earth->show();

    // Ready
    QLabel* label_ready = new QLabel(this);
    QPixmap pixmap1("Ready.png");
    pixmap1 = pixmap1.scaled(pixmap1.size() * 2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    label_ready->setPixmap(pixmap1);
    label_ready->move(400,400);
    label_ready->show();
    QTimer::singleShot(1000, label_ready, &QLabel::hide);

    // Go
    QLabel* label_go = new QLabel(this);
    QPixmap pixmap2("Go.png");
    pixmap2 = pixmap2.scaled(pixmap2.size() * 2, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    label_go->setPixmap(pixmap2);
    label_go->move(420,400);
    QTimer::singleShot(0, label_go, &QLabel::hide);
    QTimer::singleShot(1000, label_go, &QLabel::show);
    QTimer::singleShot(1500, label_go, &QLabel::hide);

    // zhou
    QLabel* label_zhou = new QLabel(this);
    QMovie* movie_zhou = new QMovie("zhou.gif");
    label_zhou->setMovie(movie_zhou);
    movie_zhou->start();
    label_zhou->move(-50,590);
    label_zhou->show();

    // 保存所有开场贴图的label，方便delete
    lb.push_back(label_go);
    lb.push_back(label_ready);
    lb.push_back(label_up);
    lb.push_back(label_zhou);

    paintTrap();// gif陷阱只打印一次

}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    paintPath();

    // 绘制car
    paintCar();


    // 判断踩陷阱
    crushTrap();

}

void Widget::paintPath()
{
    // 绘制背景，有点bug
    /*
    bg = new QLabel(this);
    QPixmap pixbg("bg.jpg");
    bg->setPixmap(pixbg);
    bg->move(0,0);
    bg->show();
    */

    // 绘制路径，仅一次.ver，未启用
    /*
    pathlb = new QLabel(this);
    QPixmap pixmap("path.png");
    pathlb->setPixmap(pixmap);
    pathlb->move(0,0);
    pathlb->show();
    */

    // 绘制路径，实时更新.ver

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen(Qt::gray);
    pen.setWidth(5);
    painter.setPen(pen);
    painter.drawPath(path);

}

void Widget::paintCar()
{
    // 定位控制点
    QPainter painter(this);
    QPointF point = path.pointAtPercent(t);

    // 绘制车轮
    QPixmap imageRoll = QPixmap("wheel.png");
    QPointF offsetRoll(imageRoll.width() / 2.0, imageRoll.height() / 2.0);
    painter.translate(point);
    painter.rotate(-path.angleAtPercent(t));
    painter.drawPixmap(-offsetRoll, imageRoll);
    painter.resetTransform();
    // 绘制车车
    QPixmap imageCar;
    if(Wait->isActive()) imageCar = QPixmap("car.png");
    else if(Muteki->isActive()) imageCar = QPixmap("carMuteki.png");
    else if(life) imageCar = QPixmap("car"+ QString::number(life) +".png");
    else imageCar = QPixmap("car.png");
    painter.translate(point);
    QPointF offsetCar(imageCar.width() / 2.0, 0);
    painter.drawPixmap(-offsetCar, imageCar);
    painter.resetTransform();
}

void Widget::paintTrap()
{
    for(auto trap:tp)
    {
        trap->label = new QLabel(this);
        trap->movie = new QMovie(trap->name + ".gif");
        trap->label->setMovie(trap->movie);
        trap->movie->start();
        trap->label->move(trap->x-trap->movie->frameRect().width()/2,trap->y-trap->movie->frameRect().height()/2);
        trap->label->show();
    }
}

void Widget::crushTrap()
{
    for(auto trap:tp) {
        // 提取当前帧
        QPointF point = path.pointAtPercent(t);
        QImage image = trap->movie->currentImage();
        // 判断碰撞与否
        for(int y = 0; y < trap->movie->frameRect().height(); y++ ){
            // 判断透明像素 -> 碰撞点
            QRgb color = image.pixel(trap->movie->frameRect().width()/2, y);
            int alpha = qAlpha(color);
            if (alpha) {
                // 该像素不透明
                qreal dx = point.x() - trap->x;
                qreal dy = point.y() + 30 - (trap->y - trap->movie->frameRect().height()/2 + y + trap->radius);
                qreal distance = qSqrt(dx * dx + dy * dy);
                if (distance <= 30) {
                    // 距离在30个单位内
                    if(!Muteki->isActive())
                    loseLife();
                }
                break;
            }
        }
    }
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    if(Wait->isActive()) return;
    if (event->key() == Qt::Key_Up) {
        // 加速
        speed = qMin(speed + 0.0005, 0.005);
    } else if (event->key() == Qt::Key_Down) {
        // 减速
        speed = qMax(speed - 0.0005, -0.005);
    }
}

void Widget::updatePosition()
{
    if (Wait->isActive()) return;
    // 关卡胜利
    if(1-t < 0.02) Youwin();
    // 控制点的位置
    t += speed/2;
    if (t < 0.00001) t = 0.00001, speed = 0;
    if (t >= 1.0) {
        t = 1.0;
        timer->stop();
    }
    //qDebug()<<path.pointAtPercent(t);
    // '可动陷阱'的位置
    for(auto trap:tp)
    {
        if(trap->name == "bird") {
            trap->updatePosition(trap->x-7, trap->y);
            if(trap->label->x()<-100) trap->updatePosition(1200, trap->label->y());
            trap->movie->start();
            trap->label->show();
        }
    }
    update();
}

void Widget::updateSpeed()
{
    speed -= gravity*sin(qDegreesToRadians(path.angleAtPercent(t)));
    if(speed) speed -= miu*gravity*(speed/abs(speed))*abs(cos(qDegreesToRadians(path.angleAtPercent(t))));
    //qDebug()<<speed;
}

void Widget::loseLife()
{
    if (Wait->isActive()) return;
    life--;
    // 进入强而有力的无敌时间
    Muteki->start(1000);
    QPointF point = path.pointAtPercent(t);
    // 加入死亡音效
    QMediaPlayer* die_music = new QMediaPlayer(this);
    die_music->setMedia(QUrl::fromLocalFile("*YOUR CODE HERE*.mp3"));// *YOUR CODE HERE*
    die_music->setVolume(40);
    die_music->play();
    QTimer::singleShot(1000, die_music, &QMediaPlayer::stop);
    am.push_back(die_music);
    // 处决动画
    QLabel* label = new QLabel(this);
    QMovie* movie = new QMovie("lose.gif");
    label->setMovie(movie);
    movie->start();
    label->move(point.x()-movie->frameRect().width()/2,point.y());
    label->show();
    QTimer::singleShot(1000, label, &QLabel::hide);
    // 关卡失败
    if(!life) Youlose();
}

void Widget::Youlose()
{
    // 停，不计算分数
    Wait -> setSingleShot(false);
    Wait -> start(5000);
    bgm -> stop();
    for(auto trap:tp) {
        trap->movie->stop();
    }
    // 播放胜利CG
    endlb = new QLabel(this);
    QMovie* movie = new QMovie("loser.gif");
    movie->setScaledSize(QSize(1400, 780));
    endlb->setMovie(movie);
    movie->start();
    endlb->move(-200,60);
    endlb->show();
    // 播放胜利音频
    QMediaPlayer* win_music = new QMediaPlayer(this);
    win_music->setMedia(QUrl::fromLocalFile("*YOUR CODE HERE*.mp3")); // *YOUR CODE HERE*
    win_music->setVolume(40);
    win_music->play();
    am.push_back(win_music);
    // 结算
    reset();
}

void Widget::Youwin()
{
    // 当前分数 = （1000秒 - 用掉的时间）* 剩下的人数
    // 计算分数 = score
    qint64 endTime = time.elapsed();
    qreal score = (1000 - endTime/1000) * life;
    qDebug()<<score;
    // 停
    bgm -> stop();
    timer->stop();
    Wait -> setSingleShot(false);
    Wait -> start(5000);
    for(auto trap:tp) {
        trap->movie->stop();
    }
    // 播放战败CG
    endlb = new QLabel(this);
    QMovie* movie = new QMovie("winner.gif");
    movie->setScaledSize(QSize(1350, 750));
    endlb->setMovie(movie);
    movie->start();
    endlb->move(-175,75);
    endlb->show();
    // 播放战败音频
    QMediaPlayer* lose_music = new QMediaPlayer(this);
    lose_music->setMedia(QUrl::fromLocalFile("*YOUR CODE HERE*.mp3")); // *YOUR CODE HERE*
    lose_music->setVolume(40);
    lose_music->play();
    am.push_back(lose_music);
    // 结算
    reset();
}

void Widget::reset()
{
    // 无论输赢，都会回到这里，设计一个窗口，重置一下数据
    for(auto trap:tp) {
        trap->label->hide();
    }
    for(auto label:lb) {
        label->hide();
        delete label->movie();
    }
    // YOUR COUD HERE
    // s.t.返回你的ui界面
}

Widget::~Widget()
{
    delete timer;
    delete Muteki;
    delete Wait;
    delete bgm;
    delete endlb->movie();
    delete endlb;
    qDeleteAll(tp);
    qDeleteAll(lb);
    qDeleteAll(am);
}

