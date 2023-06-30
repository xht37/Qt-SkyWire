#include "credits.h"

CreditsWidget::CreditsWidget(QWidget*parent):QWidget(parent)
{
    LevelPushButton* back_button = new LevelPushButton(this,true,1.5,":/images/512.png");
    back_button->move(365,530);
    connect(back_button,&LevelPushButton::clicked,[=](){
        emit back();
    });
}

//背景设置
void CreditsWidget::paintEvent(QPaintEvent*event)
{
    QPainter painter(this);
    QImage bot(":/images/500.png");
    QImage bg(":/images/615.png");
    QImage head(":/images/525.png");
    QImage lxc(":/images/lxc.png");
    QImage xht(":/images/xht.png");
    QImage ysh(":/images/ysh.png");
    bot = bot.scaled(size(),Qt::KeepAspectRatioByExpanding);
    bg=bg.scaled(size()*9/10,Qt::KeepAspectRatio);
    head = head.scaled(size()/6,Qt::KeepAspectRatio);
    lxc = lxc.scaled(size()/2,Qt::KeepAspectRatio);
    xht = xht.scaled(size()/2,Qt::KeepAspectRatio);
    ysh = ysh.scaled(size()/2,Qt::KeepAspectRatio);
    painter.drawImage(0,0,bot);
    painter.drawImage(55,40,bg);
    painter.drawImage(330,60,head);
    painter.drawImage(200,145,lxc);
    painter.drawImage(240,285,xht);
    painter.drawImage(200,425,ysh);
}
