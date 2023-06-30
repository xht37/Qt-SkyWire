#ifndef CHOOSELEVEL_H
#define CHOOSELEVEL_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include "mypushbutton.h"

class ChooseLevel : public QWidget{
    Q_OBJECT
public:
    explicit ChooseLevel(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    int total_score = 0;
signals:
    void back();
    void level1();
    void level2();
    void level3();
    //int unlocked;
public slots:
};

#endif // CHOOSELEVEL_H
