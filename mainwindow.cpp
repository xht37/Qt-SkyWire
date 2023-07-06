#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/933.png"));
    setWindowTitle("Skywire");
    ui->stackedWidget->setCurrentIndex(0);
    //qDebug() << this->width() << this->height();

    //进入选关的widget
    connect(ui->menu,&MyMenu::choose,[=](){
        level=new ChooseLevel;
        level->total_score = 0;
        ui->stackedWidget->addWidget(level);
        ui->stackedWidget->setCurrentIndex(1);

        //进入第一关
        connect(level,&ChooseLevel::level1,[=](){
           //delete ui->stackedWidget->widget(1);
           //delete ui->stackedWidget->widget(0);

           this->hide();
           this->setFocusPolicy(Qt::NoFocus);
            //ui->menu->bgm_button->on_off = true;
           ui->menu->bgm->stop();
               stackedWidget = new QStackedWidget;
               stackedWidget->setWindowIcon(QIcon(":/images/933.png"));
               widget = new Widget(NULL,1);
               //widget->show();
               //widget->setWindowTitle("skywire-1");
               widget->setFocusPolicy(Qt::StrongFocus);
               stackedWidget->addWidget(widget);
               stackedWidget->setCurrentIndex(0);
               //stackedWidget->setFocusPolicy(Qt::StrongFocus);
               stackedWidget->setWindowTitle("Skywire-1");
               stackedWidget->show();
               connect(widget,&Widget::toscore,[=](){
                   qDebug() << "this";
                   score = new ScoreWidget(0,widget->_people,widget->_time,level->total_score);
                   qDebug() << widget->_people << " " << widget->_time;
                   qDebug() << "score complete";
                   if(widget->_people > 0){
                       //level->unlocked++;
                   }
                   //delete stackedWidget->widget(0);
                   stackedWidget->addWidget(score);
                   stackedWidget->setCurrentIndex(1);
                   stackedWidget->show();
                   connect(score->back_button,&LevelPushButton::clicked,[=](){
                       this->show();
                       if(ui->menu->bgm_button->on_off){
                         ui->menu->bgm->play();
                       }
                       delete stackedWidget->widget(1);
                       delete stackedWidget->widget(0);
                       delete stackedWidget;
                       level->total_score = 0;
                   });
                   connect(score->again_button,&LevelPushButton::clicked,[=](){
                       /*widget->r_reset();
                       qDebug() << "reset over";
                       stackedWidget->setCurrentIndex(0);
                       delete stackedWidget->widget(1);*/
                       //this->show();
                       score->bgm->stop();
                       delete stackedWidget->widget(1);
                       delete stackedWidget->widget(0);
                       delete stackedWidget;
                       level->total_score = 0;
                       emit level->level1();
                   });
                   connect(score->next_button,&LevelPushButton::clicked,[=](){
                       score->bgm->pause();
                       //next = new NextWidget;
                       //stackedWidget->addWidget(next);
                       //stackedWidget->setCurrentIndex(2);
                       //connect(next->back_button,&LevelPushButton::clicked,[=](){
                          //stackedWidget->setCurrentIndex(1);
                          //score->bgm->play();
                          //delete stackedWidget->widget(2);
                       //});
                       level->total_score = widget->_people * widget->_time;
                       delete stackedWidget->widget(1);
                       delete stackedWidget->widget(0);
                       delete stackedWidget;
                       emit level->level2();
                   });
               });
               //ui->stackedWidget->addWidget(widget);
               //ui->stackedWidget->setCurrentIndex(2);
        });


        //进入第二关
        connect(level,&ChooseLevel::level2,[=](){
            //TODO
            this->hide();
            this->setFocusPolicy(Qt::NoFocus);
            ui->menu->bgm->stop();
                stackedWidget = new QStackedWidget;
                stackedWidget->setWindowIcon(QIcon(":/images/933.png"));
                widget = new Widget(NULL,2);
                //widget->show();
                widget->setFocusPolicy(Qt::StrongFocus);
                stackedWidget->addWidget(widget);
                stackedWidget->setCurrentIndex(0);
                //stackedWidget->setFocusPolicy(Qt::StrongFocus);
                stackedWidget->setWindowTitle("Skywire-2");
                stackedWidget->show();
                connect(widget,&Widget::toscore,[=](){
                    qDebug() << "this";
                    score = new ScoreWidget(0,widget->_people,widget->_time,level->total_score);
                    qDebug() << widget->_people << " " << widget->_time;
                    qDebug() << "score complete";
                    //delete stackedWidget->widget(0);
                    stackedWidget->addWidget(score);
                    //qDebug() << "here";
                    stackedWidget->setCurrentIndex(1);
                    //qDebug() << "here";
                    stackedWidget->show();
                    //qDebug() << "here";
                    connect(score->back_button,&LevelPushButton::clicked,[=](){
                        this->show();
                        if(ui->menu->bgm_button->on_off){
                            ui->menu->bgm->play();
                        }
                        delete stackedWidget->widget(1);
                        delete stackedWidget->widget(0);
                        delete stackedWidget;
                        level->total_score = 0;
                    });
                    connect(score->again_button,&LevelPushButton::clicked,[=](){
                        /*widget->r_reset();
                        qDebug() << "reset over";
                        stackedWidget->setCurrentIndex(0);
                        delete stackedWidget->widget(1);*/
                        //this->show();
                        score->bgm->stop();
                        //level->total_score -= (widget->_people*widget->_time);
                        delete stackedWidget->widget(1);
                        delete stackedWidget->widget(0);
                        delete stackedWidget;

                        emit level->level2();
                    });
                    connect(score->next_button,&LevelPushButton::clicked,[=](){
                        score->bgm->pause();
                         /*next = new NextWidget;
                         stackedWidget->addWidget(next);
                         stackedWidget->setCurrentIndex(2);
                         connect(next->back_button,&LevelPushButton::clicked,[=](){
                            stackedWidget->setCurrentIndex(1);
                            score->bgm->play();
                            delete stackedWidget->widget(2);
                         });*/
                        level->total_score += widget->_people * widget->_time;
                        delete stackedWidget->widget(1);
                        delete stackedWidget->widget(0);
                        delete stackedWidget;
                        emit level->level3();
                    });
                });
        });

        //进入第三关
        connect(level,&ChooseLevel::level3,[=](){
            //TODO
            this->hide();
            this->setFocusPolicy(Qt::NoFocus);
            ui->menu->bgm->stop();
                stackedWidget = new QStackedWidget;
                stackedWidget->setWindowIcon(QIcon(":/images/933.png"));
                widget = new Widget(NULL,3);
                //widget->show();
                widget->setFocusPolicy(Qt::StrongFocus);
                stackedWidget->addWidget(widget);
                stackedWidget->setCurrentIndex(0);
                //stackedWidget->setFocusPolicy(Qt::StrongFocus);
                stackedWidget->setWindowTitle("Skywire-3");
                stackedWidget->show();
                connect(widget,&Widget::toscore,[=](){
                    qDebug() << "this";
                    score = new ScoreWidget(0,widget->_people,widget->_time,level->total_score);
                    qDebug() << widget->_people << " " << widget->_time;
                    qDebug() << "score complete";
                    //delete stackedWidget->widget(0);
                    stackedWidget->addWidget(score);
                    //qDebug() << "here";
                    stackedWidget->setCurrentIndex(1);
                    //qDebug() << "here";
                    stackedWidget->show();
                    //qDebug() << "here";
                    connect(score->back_button,&LevelPushButton::clicked,[=](){
                        this->show();
                        if(ui->menu->bgm_button->on_off){
                            ui->menu->bgm->play();
                        }
                        delete stackedWidget->widget(1);
                        delete stackedWidget->widget(0);
                        delete stackedWidget;
                        level->total_score = 0;
                    });
                    connect(score->again_button,&LevelPushButton::clicked,[=](){
                        /*widget->r_reset();
                        qDebug() << "reset over";
                        stackedWidget->setCurrentIndex(0);
                        delete stackedWidget->widget(1);*/
                        //this->show();
                        score->bgm->stop();
                        //level->total_score -= (widget->_people*widget->_time);
                        delete stackedWidget->widget(1);
                        delete stackedWidget->widget(0);
                        delete stackedWidget;

                        emit level->level3();
                    });
                    connect(score->next_button,&LevelPushButton::clicked,[=](){
                        score->bgm->pause();
                         next = new NextWidget;
                         stackedWidget->addWidget(next);
                         stackedWidget->setCurrentIndex(2);
                         connect(next->back_button,&LevelPushButton::clicked,[=](){
                            stackedWidget->setCurrentIndex(1);
                            score->bgm->play();
                            delete stackedWidget->widget(2);
                         });
                    });
                });
        });
        //返回主菜单
        connect(level,&ChooseLevel::back,[=](){
            ui->stackedWidget->setCurrentIndex(0);
            delete ui->stackedWidget->widget(1);
        });
    });

    //进入帮助的widget
    connect(ui->menu,&MyMenu::helpclicked,[=](){
        help = new HelpWidget;
        ui->stackedWidget->addWidget(help);
        ui->stackedWidget->setCurrentIndex(1);

        connect(help,&HelpWidget::back,[=](){
           ui->stackedWidget->setCurrentIndex(0);
           delete ui->stackedWidget->widget(1);
        });
    });

    //进入分数的widget
    /*connect(ui->menu,&MyMenu::scoreclicked,[=](){
        this->hide();
        score = new ScoreWidget;
        score->setFixedSize(1001,901);
        score->show();
        //ui->stackedWidget->addWidget(score);
        //ui->stackedWidget->setCurrentIndex(1);

        connect(score,&ScoreWidget::back,[=](){
           this->show();
           ui->stackedWidget->setCurrentIndex(0);
           delete score;
        });
    });*/

    //进入credits的widget
    connect(ui->menu,&MyMenu::creditsclicked,[=](){
        credits = new CreditsWidget;
        ui->stackedWidget->addWidget(credits);
        ui->stackedWidget->setCurrentIndex(1);

        connect(credits,&CreditsWidget::back,[=](){
           ui->stackedWidget->setCurrentIndex(0);
           delete ui->stackedWidget->widget(1);
        });
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

