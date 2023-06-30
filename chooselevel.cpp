#include "chooselevel.h"

ChooseLevel::ChooseLevel(QWidget*parent):QWidget(parent)
{
    LevelPushButton* level_button[20];
    //unlocked = _unlocked;

    LevelPushButton* back_button = new LevelPushButton(this,true,1.5,":/images/512.png");
    back_button->move(365,530);
    connect(back_button,&LevelPushButton::clicked,[=](){
        emit back();
    });
    level_button[0] = new LevelPushButton(this,true,1.7,":/images/one_pass.png",":/images/one_enter.png");
    level_button[0]->move(100,100);
    //if(unlocked > 1)
    level_button[1] = new LevelPushButton(this,true,1.7,":/images/two_pass.png",":/images/two_enter.png");
    level_button[1]->move(230,100);
    level_button[2] = new LevelPushButton(this,true,1.7,":/images/three_pass.png",":/images/three_enter.png");
    level_button[2]->move(360,100);
    connect(level_button[0],&LevelPushButton::clicked,[=](){
        emit level1();
    });
    connect(level_button[1],&LevelPushButton::clicked,[=](){
        emit level2();
    });
    connect(level_button[2],&LevelPushButton::clicked,[=](){
        emit level3();
    });
}

//背景设置
void ChooseLevel::paintEvent(QPaintEvent*event)
{
    QPainter painter(this);
    QImage bot(":/images/500.png");
    QImage bg(":/images/615.png");
    QImage frame(":/images/581.png");
    QImage head(":/images/927.png");
    bot = bot.scaled(size(),Qt::KeepAspectRatioByExpanding);
    bg=bg.scaled(size()*9/10,Qt::KeepAspectRatio);
    frame = frame.scaled(size()/7,Qt::KeepAspectRatio);
    head = head.scaled(size()/3,Qt::KeepAspectRatio);
    painter.drawImage(0,0,bot);
    painter.drawImage(55,40,bg);
    painter.drawImage(270,60,head);
    for(int i=0;i<4;++i)
        for(int j=0;j<5;++j){
            if(i!=0 || j!=0) painter.drawImage(100+130*j,100+110*i,frame);
        }
}
