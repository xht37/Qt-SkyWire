#ifndef ADD_MAP_H
#define ADD_MAP_H

#include "widget.h"

void addPath(QPainterPath& path,int p)
{
    if(p==1) {
        path.moveTo(130, 692);
        path.lineTo(166, 692);
        path.arcTo(166-25, 692-50,50,50,-90,45);
        path.lineTo(396,470);
        path.arcTo(396-7, 470-7,50,50,135,-45);
        path.arcTo(423-150, 463,300,300,90,-270);
        path.arcTo(273-50, 610-25,50,50,0,45);
        path.lineTo(78,297);
        path.arcTo(78-25, 297-100,100,100,-140,-135);
        path.lineTo(200,197);
        path.arcTo(200-50, 197-100,100,100,-90,45);
        path.lineTo(250,162);
        path.arcTo(250-14, 162-14,100,100,135,-45);
        path.lineTo(800,148);
        path.arcTo(800, 148,100,100,90,-135);
        path.lineTo(600,400);
        path.lineTo(800,425);
        path.lineTo(600,450);
        path.lineTo(800,475);
        path.lineTo(600,500);
        path.lineTo(800,525);
        path.lineTo(850,525);
    }
    else if(p==2) {
        path.moveTo(216,183);
        path.lineTo(848,183);
        path.arcTo(848,183,100,100,90,-135);
        path.lineTo(932,270);
        path.lineTo(832,370);

        path.arcTo(832-50-50/1.4,370-50-50/1.4,100,100,-45,-90);
        path.lineTo(832-100/1.4,370);
        path.lineTo(732-100/1.4,270);
        path.arcTo(732-150/1.4-50,270-50+50/1.4,100,100,45,90);
        path.lineTo(732-200/1.4,270);
        path.lineTo(632-200/1.4,370);

        path.arcTo(632-50-250/1.4,370-50-50/1.4,100,100,-45,-90);
        path.lineTo(632-300/1.4,370);
        path.lineTo(532-300/1.4,270);
        path.arcTo(532-350/1.4-50,270-50+50/1.4,100,100,45,90);
        path.lineTo(532-400/1.4,270);
        path.lineTo(146,370);

        path.arcTo(146-50+50/1.4,370-50+50/1.4,100,100,135,180);
        path.lineTo(146+100/1.4,370+100/1.4);
        path.lineTo(146+50+100/1.4,370-50+100/1.4);

        path.arcTo(146+150/1.4,370-100+150/1.4,100,100,135,-90);
        path.lineTo(146+50+200/1.4,370-50+100/1.4);
        path.lineTo(146+150+200/1.4,370+50+100/1.4);
        path.arcTo(146+100+250/1.4,370+50/1.4,100,100,-135,90);
        path.lineTo(146+150+300/1.4,370+50+100/1.4);
        path.lineTo(146+250+300/1.4,370-50+100/1.4);
        path.arcTo(146+200+350/1.4,370-100+150/1.4,100,100,135,-90);
        path.lineTo(146+250+400/1.4,370-50+100/1.4);
        path.lineTo(146+400+400/1.4,370+100+100/1.4);

        path.cubicTo(100, 600, 10, 700, 448, 700);
        path.lineTo(848,700);
    }
    else if(p==3) {
        path.moveTo(530,710);

        path.lineTo(700,710);
        path.arcTo(700-200,710-400,400,400,-90,90);

        path.lineTo(900,170);
        path.lineTo(700,200);
        path.lineTo(700,500);
        path.lineTo(500,400);
        path.lineTo(300,500);
        path.lineTo(300,200);
        path.lineTo(100,170);
        path.lineTo(100,510);
        path.arcTo(100,510-200,400,400,180,90);
        path.lineTo(300,710);
        path.lineTo(380,710);
    }
}

void addTrap(QVector<Trap*>& tp, int p)
{
    if(p==1) {
        tp.push_back(new Trap(421,520,"giraff"));
        tp.push_back(new Trap(367,150,"frog"));
        tp.push_back(new Trap(417,150,"frog"));
        tp.push_back(new Trap(467,150,"frog"));
        tp.push_back(new Trap(517,150,"frog"));
        tp.push_back(new Trap(820,130,"giraff"));
        tp.push_back(new Trap(120,180,"giraff"));
        tp.push_back(new Trap(-25,300,"bird"));
        tp.push_back(new Trap(-25,400,"bird"));
        tp.push_back(new Trap(-25,500,"bird"));
        tp.push_back(new Trap(-25,600,"bird"));
        tp.push_back(new Trap(700,500,"giraff"));
        tp.push_back(new Trap(10,665,"zhou"));
    }
    else if(p==2) {
        tp.push_back(new Trap(303,368,"giraff"));
        tp.push_back(new Trap(650,368,"giraff"));
        tp.push_back(new Trap(620,242,"giraff"));
        tp.push_back(new Trap(313,650,"frog"));
        tp.push_back(new Trap(363,650,"frog"));
        tp.push_back(new Trap(413,650,"frog"));
        tp.push_back(new Trap(463,650,"frog"));
        tp.push_back(new Trap(1225,250,"bird"));
        tp.push_back(new Trap(1525,300,"bird"));
        tp.push_back(new Trap(2525,525,"bird"));
        tp.push_back(new Trap(70,153,"yuan"));
    }
    else if(p==3) {
        tp.push_back(new Trap(1700,425,"bird"));
        tp.push_back(new Trap(1600,200,"bird"));
        tp.push_back(new Trap(1200,250,"bird"));
        tp.push_back(new Trap(1500,300,"bird"));
        tp.push_back(new Trap(1300,350,"bird"));
        tp.push_back(new Trap(1400,400,"bird"));
        tp.push_back(new Trap(1400,450,"bird"));
        tp.push_back(new Trap(1300,500,"bird"));
        tp.push_back(new Trap(1500,550,"bird"));
        tp.push_back(new Trap(1200,600,"bird"));
        tp.push_back(new Trap(1600,650,"bird"));
        qreal t = 700;
        tp.push_back(new Trap(2000+t,425,"bird"));
        tp.push_back(new Trap(1600+t,200,"bird"));
        tp.push_back(new Trap(1200+t,250,"bird"));
        tp.push_back(new Trap(1500+t,300,"bird"));
        tp.push_back(new Trap(1300+t,350,"bird"));
        tp.push_back(new Trap(1400+t,400,"bird"));
        tp.push_back(new Trap(1400+t,450,"bird"));
        tp.push_back(new Trap(1300+t,500,"bird"));
        tp.push_back(new Trap(1500+t,550,"bird"));
        tp.push_back(new Trap(1200+t,600,"bird"));
        tp.push_back(new Trap(1600+t,650,"bird"));

        tp.push_back(new Trap(500,217,"6f"));
        tp.push_back(new Trap(60,733,"ee"));
    }
}

#endif // ADD_MAP_H
