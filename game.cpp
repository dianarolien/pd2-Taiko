#include "game.h"
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <QMediaPlayer>

Game::Game(QWidget *parent)
{
    setWindowTitle(tr("養豬場"));
    scene = new QGraphicsScene();

    //設定背景圖片
    QPixmap *pixmap = new QPixmap(":/pictures/bakground.png");
    scene->setBackgroundBrush(pixmap->scaled(720,540,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    setScene(scene);

    //add score object
    score = new Score();
    scene->addItem(score);

    //add time object
    fri = new Fri();
    scene->addItem(fri->time);

    //create a object 來發射豬崽
    rect = new Myrect();
    scene->addItem(rect);

    //add drump
    bottom = new Bottom();
    scene->addItem(bottom);

    //把按鍵控制權交給bottom
    bottom->setFlag(QGraphicsItem::ItemIsFocusable);
    bottom->setFocus();

    //背景音樂
    QMediaPlayer * bgm = new QMediaPlayer();
    bgm->setMedia(QUrl("qrc:/sounds/Snow_Town.MP3"));
    bgm->play();

}
