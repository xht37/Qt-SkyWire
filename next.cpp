#include "next.h"

NextWidget::NextWidget(QWidget*parent):QWidget(parent)
{
    back_button = new LevelPushButton(this,true,2,":/images/512.png");
    back_button->move(450,800);
    connect(back_button,&LevelPushButton::clicked,[=](){
        emit back();
    });
}

//背景设置
void NextWidget::paintEvent(QPaintEvent*event)
{
    QPainter painter(this);
    QImage bot(":/images/genshit.png");
    //QImage bg(":/images/615.png");
    //QImage nhelp(":/images/no_help.png");
    //QImage head(":/images/540.png");
    bot = bot.scaled(size(),Qt::KeepAspectRatioByExpanding);
    //bg=bg.scaled(size()*9/10,Qt::KeepAspectRatio);
    //nhelp = nhelp.scaled(size()/2,Qt::KeepAspectRatio);
    //head = head.scaled(size()/10,Qt::KeepAspectRatio);
    painter.drawImage(0,0,bot);
    //painter.drawImage(55,40,bg);
    //painter.drawImage(360,60,head);
    //painter.drawImage(210,300,nhelp);
}
