#include "mypushbutton.h"
#include <QDebug>
#include <QString>
#include <QPropertyAnimation>
#include <QBitmap>

MyPushButton::MyPushButton(QWidget* parent,bool mask,QString normalImg,QString pressedImg):normalImgPath(normalImg),pressedImgPath(pressedImg),QPushButton(parent)
{
    setCursor(Qt::PointingHandCursor);
    QPixmap pix;
    bool ret = pix.load(normalImgPath);
    pix = pix.scaled(pix.size() * 1.5);
    if(!ret){
        qDebug() << "fail to load picture";
        return;
    }
    setFixedSize(pix.width(),pix.height());
    if(mask) setMask(pix.mask());
    setStyleSheet("QPushButton{border:0px;}");
    setIcon(pix);//设置按钮图像
    setIconSize(QSize(pix.width(),pix.height()));//设置图像大小
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    move(x()+1,y()+1);//稍微动一下
    return QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{

    move(x()-1,y()-1);//回到原位
    return QPushButton::mouseReleaseEvent(e);
}

void MyPushButton::enterEvent(QEvent *event)
{

    if(pressedImgPath!="")
    {
        //鼠标进入button后替换图像
        QPixmap pix;
        pix.load(pressedImgPath);
        pix=pix.scaled(pix.size()*1.1);
        setIcon(pix);
    }
    return QPushButton::enterEvent(event);
}

void MyPushButton::leaveEvent(QEvent *event)
{
   if(pressedImgPath!="")
   {
             QPixmap pix;
             pix.load(normalImgPath);
             pix=pix.scaled(pix.size()*1.5);
             setIcon(pix);
   }
   return QPushButton::leaveEvent(event);
}

ReplaceImgButton::ReplaceImgButton(QWidget*parent,bool mask,QString normalImg,QString pressedImg):MyPushButton(parent,mask,normalImg,pressedImg){
    setCursor(Qt::PointingHandCursor);
    bool ret1 = pix1.load(normalImgPath);
    on_off = true;
    pix1 = pix1.scaled(pix1.size() * 1.5);
    if(!ret1){
        qDebug() << "fail to load picture";
        return;
    }
    setFixedSize(pix1.width(),pix1.height());
    //if(!mask) setMask(pix1.mask());
    setStyleSheet("QPushButton{border:0px;}");

    bool ret2 = pix2.load(pressedImgPath);
    pix2 = pix2.scaled(pix2.size() * 1.5);
    if(!ret2){
        qDebug() << "fail to load picture";
        return;
    }
    setFixedSize(pix2.width(),pix2.height());
    //if(mask) setMask(pix2.mask());
    setStyleSheet("QPushButton{border:0px;}");
    if(on_off){
        setIcon(pix1);//设置按钮图像
        setIconSize(QSize(pix1.width(),pix1.height()));//设置图像大小
    }
    else{
        setIcon(pix2);//设置按钮图像
        setIconSize(QSize(pix2.width(),pix2.height()));//设置图像大小
    }

}

void ReplaceImgButton::mouseReleaseEvent(QMouseEvent* e){
    on_off = !on_off;
    if(on_off){
        setIcon(pix1);
    }
    else{
        setIcon(pix2);
    }
    return QPushButton::mouseReleaseEvent(e);
}

void ReplaceImgButton::enterEvent(QEvent *event){
    return QPushButton::enterEvent(event);
}

void ReplaceImgButton::leaveEvent(QEvent *event){
    return QPushButton::leaveEvent(event);
}

LevelPushButton::LevelPushButton(QWidget* parent,bool mask,double magni,QString normalImg,QString pressedImg):MyPushButton(parent,mask,normalImg,pressedImg){
    setCursor(Qt::PointingHandCursor);
    QPixmap pix;
    mag = magni;
    bool ret = pix.load(normalImgPath);
    pix = pix.scaled(pix.size() * mag);
    if(!ret){
        qDebug() << "fail to load picture";
        return;
    }
    setFixedSize(pix.width(),pix.height());
    if(mask) setMask(pix.mask());
    setStyleSheet("QPushButton{border:0px;}");
    setIcon(pix);//设置按钮图像
    setIconSize(QSize(pix.width(),pix.height()));//设置图像大小
}

void LevelPushButton::leaveEvent(QEvent *event)
{
   if(pressedImgPath!="")
   {
             QPixmap pix;
             pix.load(normalImgPath);
             pix=pix.scaled(pix.size()*mag);
             setIcon(pix);
   }
   return QPushButton::leaveEvent(event);
}

void LevelPushButton::enterEvent(QEvent *event)
{

    if(pressedImgPath!="")
    {
        //鼠标进入button后替换图像
        QPixmap pix;
        pix.load(pressedImgPath);
        pix=pix.scaled(pix.size()*mag);
        setIcon(pix);
    }
    return QPushButton::enterEvent(event);
}
