#ifndef HELP_H
#define HELP_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include "mypushbutton.h"

class HelpWidget : public QWidget{
    Q_OBJECT
public:
    explicit HelpWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
signals:
    void back();
public slots:
};

#endif // HELP_H
