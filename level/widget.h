#ifndef WIDGET_H
#define WIDGET_H

#include "trap.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *event) override;
    void paintPath();
    void paintCar();
    void paintTrap();
    void crushTrap();
    void keyPressEvent(QKeyEvent *event) override;
    void updatePosition();
    void updateSpeed();
    void loseLife();
    void Youlose();
    void Youwin();
    void reset();

private:
    Ui::Widget *ui;
    QPainterPath path; // 轨道
    QTimer *timer; // 速度更新时间，计时器
    QElapsedTimer time; // 程序运行时间
    qreal t; // 路径前进比例，控制车车位置
    qreal speed; // 车车速度
    int life; //剩余人数 <= 3
    QVector<Trap*> tp; // 陷阱
    QTimer *Muteki; // 无敌时间
    QTimer *Wait; // 开场、结算时，不可操作的时间
    QLabel* earth; // 拼凑出的伪背景
    QVector<QLabel*> lb; // 开场用到的贴图
    QLabel* endlb; // 结算用到的贴图
    QMediaPlayer* bgm; // bgm
    QVector<QMediaPlayer*> am; // 保存所有临时音效，方便delete
};

#endif // WIDGET_H
