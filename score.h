#ifndef SCORE_H
#define SCORE_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include "mypushbutton.h"

class ScoreWidget : public QWidget{
    Q_OBJECT
public:
    explicit ScoreWidget(QWidget *parent = 0,int _people = 0,int _time = 0,int total_score = 0);
    void paintEvent(QPaintEvent *event);
    int people;
    int time;
    int total_score;
    LevelPushButton *back_button;
    LevelPushButton *next_button;
    LevelPushButton *again_button;
    QMediaPlaylist *bgmlist;
    QMediaPlayer *bgm;
signals:
    void back();
public slots:
};

#endif // SCORE_H
