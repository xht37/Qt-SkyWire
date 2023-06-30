#include "help.h"

HelpWidget::HelpWidget(QWidget*parent):QWidget(parent)
{
    LevelPushButton* back_button = new LevelPushButton(this,true,1.5,":/images/512.png");
    back_button->move(365,530);
    connect(back_button,&LevelPushButton::clicked,[=](){
        emit back();
    });
}

//背景设置
void HelpWidget::paintEvent(QPaintEvent*event)
{
    QPainter painter(this);
    QImage bot(":/images/500.png");
    QImage bg(":/images/615.png");
    QImage nhelp(":/images/help_pic.png");
    QImage head(":/images/540.png");
    bot = bot.scaled(size(),Qt::KeepAspectRatioByExpanding);
    bg=bg.scaled(size()*9/10,Qt::KeepAspectRatio);
    nhelp = nhelp.scaled(size()*3/4,Qt::KeepAspectRatio);
    head = head.scaled(size()/10,Qt::KeepAspectRatio);
    painter.drawImage(0,0,bot);
    painter.drawImage(55,40,bg);
    painter.drawImage(360,60,head);
    painter.drawImage(100,90,nhelp);
}
