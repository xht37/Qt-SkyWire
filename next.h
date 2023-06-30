#ifndef NEXT_H
#define NEXT_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include "mypushbutton.h"

class NextWidget : public QWidget{
    Q_OBJECT
public:
    explicit NextWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    LevelPushButton *back_button;
signals:
    void back();
public slots:
};

#endif // NEXT_H
