#include "score.h"
#include <QDebug>

ScoreWidget::ScoreWidget(QWidget*parent,int _people,int _time,int _total_score):QWidget(parent)
{
    people = _people;
    time = _time;
    total_score = _total_score;
    back_button = new LevelPushButton(this,true,2,":/images/512.png");
    next_button = new LevelPushButton(this,true,2,":/images/601");
    again_button = new LevelPushButton(this,true,2,":/images/637.png");
    back_button->move(100,780);
    next_button->move(680,780);
    again_button->move(350,780);

    bgmlist=new QMediaPlaylist();
    bgmlist->addMedia(QUrl("qrc:/sounds/gerudo.mp3"));
    bgmlist->setPlaybackMode(QMediaPlaylist::Loop);

    bgm = new QMediaPlayer();
    bgm->setPlaylist(bgmlist);
    bgm->setVolume(5);
    bgm->play();
    connect(back_button,&LevelPushButton::clicked,[=](){
        bgm->stop();
        emit back();
    });
}

//背景设置
void ScoreWidget::paintEvent(QPaintEvent*event)
{
    QPainter painter(this);
    QImage bot(":/images/scorewid.png");

    bot = bot.scaled(size(),Qt::KeepAspectRatioByExpanding);
    painter.drawImage(0,0,bot);
    QImage number[10] = {QImage(":/images/767.png"),QImage(":/images/770.png"),QImage(":/images/773.png"),QImage(":/images/776.png"),
                        QImage(":/images/779.png"),QImage(":/images/782.png"),QImage(":/images/785.png"),QImage(":/images/788.png"),
                        QImage(":/images/791.png"),QImage(":/images/794.png")};
    for(int i=0;i<10;++i){
        number[i] = number[i].scaled(size()/20,Qt::KeepAspectRatio);
    }
    painter.drawImage(800,185,number[people]);
    int num1[4];
    int num2[4];
    int k=3;
    //打印剩余时间
    int tmp_time = time;
    while(k>=0){
        num1[k] = tmp_time % 10;
        tmp_time = tmp_time/10;
        k--;
    }
    for(int i=0;i<4;++i){
        painter.drawImage(695+35*i,320,number[num1[i]]);
    }
    //打印本关得分
    int level_score = people * time;
    //qDebug() << "people " << people << "time" << time;
    //qDebug() << "level_score " <<level_score;
    k=3;
    while(k>=0){
        num2[k] = level_score%10;
        level_score = level_score/10;
        k--;
    }
    for(int i=0;i<4;++i){
        painter.drawImage(695+35*i,455,number[num2[i]]);
        //painter.drawImage(695+35*i,665,number[num2[i]]);
    }
    int all = total_score + people*time;
    k=3;
    while(k>=0){
        num2[k] = all%10;
        all = all/10;
        k--;
    }
    for(int i=0;i<4;++i){
        painter.drawImage(695+35*i,665,number[num2[i]]);
    }
}
