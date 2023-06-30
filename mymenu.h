#ifndef MYMENU_H
#define MYMENU_H

#include <QWidget>
#include<QImage>
#include<QPainter>
#include<QtCore/QCoreApplication>
#include<QtMultimedia/QMediaPlayer>
#include<QMediaPlaylist>
#include <QSound>
#include"mypushbutton.h"
class MyMenu : public QWidget
{
    Q_OBJECT
public:
    explicit MyMenu(QWidget *parent = 0);
    QMediaPlaylist* bgmlist;
    ReplaceImgButton* bgm_button;
    QMediaPlayer* bgm;
    QSound *bg;
    void paintEvent(QPaintEvent *event);
signals:
    void readyforquit();
    void helpclicked();
    void scoreclicked();
    void creditsclicked();
    void unableclicked();
    void choose();
public slots:
};

#endif // MYMENU_H
