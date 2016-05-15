#include "myrect.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include "game.h"
#include <QDebug>

extern Game * game ;

Myrect::Myrect()
{
    //產生發射豬崽的物件
    setRect(800,0,1,1);
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(setBullet()));
    //隨機發射
    int random_number = rand()%700+300;
    timer->start(random_number);
}

void Myrect::timer1()
{
    timer->start();
}

void Myrect::setBullet()
{
    //隨機發射 迷你豬 or 炸豬排
    int ran = rand()%2;
    if(ran==0)
    {
        Bullet * bullet = new Bullet();
        scene()->addItem(bullet);
    }
    if(ran==1)
    {
        Bullet2 * bullet2 = new Bullet2();
        scene()->addItem(bullet2);
    }
    if(game->key2==2)
    {
        timer->stop();
        return ;
    }
    //每發射一次時間重新設定
    timer->stop();
    int random_number = rand()%700+300;
    timer->start(random_number);
 }

