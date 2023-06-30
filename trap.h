#ifndef TRAP_H
#define TRAP_H

#include <QWidget>
#include <QElapsedTimer>
#include <QVector>
#include <QApplication>
#include <QPainter>
#include <QPainterPath>
#include <QKeyEvent>
#include <QTimer>
#include <QtMath>
#include <QDebug>
#include <QImage>
#include <QLabel>
#include <QMovie>
#include <QString>
#include <QMediaPlayer>

class Trap
{
public:
   qreal x,y;
   QString name;
   QLabel *label;
   QMovie *movie;
   qreal radius;
   qreal angle;
   Trap(qreal xx=0,qreal yy=1100,QString n="",qreal a = 0):x(xx),y(yy),name(n),angle(a)
   {
       if(name == "giraff") radius = 17.5;
       else if(name == "frog") radius = 12.5;
       else if(name == "bird") radius = 20;
   }
   void updatePosition(qreal xx,qreal yy)
   {
       x=xx;
       y=yy;
       label->move(x-movie->frameRect().width()/2,y-movie->frameRect().height()/2);
   }
   ~Trap()
   {
       delete label;
       delete movie;
   }
};



#endif // TRAP_H
