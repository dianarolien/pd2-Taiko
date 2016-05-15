#include "dialog.h"
#include "ui_dialog.h"
#include "myrect.h"
#include "score.h"
#include "game.h"
#include "bottom.h"
#include <QFont>
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QLabel>
#include <QGraphicsView>

extern Game *game;
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    int level;
    if(game->score->getScore()<=0)
        level = -100;
    if(game->score->getScore()<10 && game->score->getScore()>0)
        level = 0;
    if(game->score->getScore()<20 && game->score->getScore()>=10)
        level = 1;
    if(game->score->getScore()<30 && game->score->getScore()>=20)
        level = 2;
    if(game->score->getScore()<40 && game->score->getScore()>=30)
        level = 3;
    if(game->score->getScore()<50 && game->score->getScore()>=40)
        level = 4;
    if(game->score->getScore()>=50)
        level = 5;

    setWindowTitle(tr("Game Over"));

    QLabel * label =  new QLabel(this);

    //設置字體大小
    QFont ft;
    ft.setPointSize(16);
    label->setFont(ft);

    //設置字體顏色
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::blue);
    label->setPalette(pa);

    QString str = QString("Score: "+QString::number(game->score->getScore()));
    label->setText(str);
    label->setGeometry(45,165,100,100);        //設定位置大小
    label->setAlignment(Qt::AlignLeft);


    QLabel * label2 =  new QLabel(this);

    //設置字體大小
    QFont ft2;
    ft2.setPointSize(16);
    label2->setFont(ft2);

    //設置字體顏色
    QPalette pa2;
    pa2.setColor(QPalette::WindowText,Qt::blue);
    label2->setPalette(pa2);

    QString str2 = QString("Level: "+QString::number(level));
    label2->setText(str2);
    label2->setGeometry(45,195,100,100);        //設定位置大小
    label2->setAlignment(Qt::AlignLeft);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_2_clicked()
{
    exit(1);
}

void Dialog::on_pushButton_clicked()
{
    //restart and initialize objects
    game->key2 = 1;
    this->hide();
    game->score->initial();
    game->rect->timer1();
}
