#include "widget.h"
#include <QApplication>
#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QKeyEvent>
#include <QTimer>
#include <QtMath>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Widget w;
    w.show();
    return app.exec();
}
