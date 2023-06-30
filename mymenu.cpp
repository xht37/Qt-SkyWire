#include "mymenu.h"

MyMenu::MyMenu(QWidget *parent) : QWidget(parent)
{
    //bgm播放
    bgmlist=new QMediaPlaylist();
    bgmlist->addMedia(QUrl("qrc:/sounds/poke.mp3"));
    bgmlist->setPlaybackMode(QMediaPlaylist::Loop);

    bgm = new QMediaPlayer();
    bgm->setPlaylist(bgmlist);
    bgm->setVolume(20);
    bgm->play();
    //bg = new QSound(":/sounds/weibai.wav");
    //bg->setLoops(-1);
    //bg->play();

    //按钮设置

    //音乐按钮
    bgm_button=new ReplaceImgButton(this,true,":images/595.png",":/images/mscoff.png");
    bgm_button->move(700,30);
    connect(bgm_button,&ReplaceImgButton::clicked,[=](){
        //bgm_button->on_off = bgm_button->on_off;
        //qDebug() << "clicked";
        if(!bgm_button->on_off) {
            bgm->pause();
            //bg->stop();
            //qDebug() << "stop";
        }
        else {
            bgm->play();
            //bg->play();
        }
    });

    //选关
    MyPushButton* play_button=new MyPushButton(this,true,":/images/611.png");
    play_button->move(380,340);
    connect(play_button,&MyPushButton::clicked,[=](){
        //bgm->stop();
        //qDebug() << "play pressed";
        emit choose();
    });

    //查看分数
    /*MyPushButton* scores_button=new MyPushButton(this,true,":/images/648.png");
    scores_button->move(365,450);
    connect(scores_button,&MyPushButton::clicked,[=](){
        emit scoreclicked();
    });*/

    //查看帮助
    MyPushButton* help_button=new MyPushButton(this,true,":/images/540.png");
    help_button->move(380,415);
    connect(help_button,&MyPushButton::clicked,[=](){
        emit helpclicked();
    });

    //制作人员
    MyPushButton* credits_button=new MyPushButton(this,true,":/images/525.png");
    credits_button->move(355,490);
    connect(credits_button,&MyPushButton::clicked,[=](){
        emit creditsclicked();
    });

}
//背景设置
void MyMenu::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QImage im(":/images/721.png");
    QImage bg(":/images/500.png");
    im=im.scaled(size(),Qt::KeepAspectRatio);
    bg=bg.scaled(size(),Qt::KeepAspectRatioByExpanding);
    painter.drawImage(0,0,bg);
    painter.drawImage(0,100,im);
}
