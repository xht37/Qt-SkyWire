#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDockWidget>
#include <QStackedWidget>
#include <QDebug>
#include "chooselevel.h"
#include "help.h"
#include "score.h"
#include "credits.h"
#include "widget.h"
#include "next.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ChooseLevel *level;
    HelpWidget *help;
    ScoreWidget *score;
    CreditsWidget *credits;
    Widget *widget;
    QStackedWidget *stackedWidget;
    NextWidget *next;
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
