#ifndef CREDITS_H
#define CREDITS_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include "mypushbutton.h"

class CreditsWidget : public QWidget{
    Q_OBJECT
public:
    explicit CreditsWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
signals:
    void back();
public slots:
};

#endif // CREDITS_H
