#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    MyPushButton(QWidget* parent,bool mask,QString normalImg,QString pressedImg="");
    QString normalImgPath;
    QString pressedImgPath;
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *e);
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);
signals:

public slots:
};

class ReplaceImgButton:public MyPushButton
{
    Q_OBJECT
public:
    ReplaceImgButton(QWidget*parent,bool mask,QString normalImg,QString pressedImg);
    QPixmap pix1,pix2;
    bool on_off;
    virtual void mouseReleaseEvent(QMouseEvent *e);
    virtual void enterEvent(QEvent* event);
    virtual void leaveEvent(QEvent* event);
};

class LevelPushButton:public MyPushButton
{
    Q_OBJECT
public:
    double mag;
    LevelPushButton(QWidget*parent,bool mask,double magni,QString normalImg,QString pressedImg="");
    virtual void enterEvent(QEvent* event);
    virtual void leaveEvent(QEvent* event);
};

#endif // MYPUSHBUTTON_H
