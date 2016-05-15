#include "bullet2.h"
#include <QTimer>
#include <QGraphicsScene>
#include "bottom.h"
#include "score.h"
#include "game.h"
#include <QDebug>
#include <QGraphicsItem>

extern Game * game;

Bullet2::Bullet2()
{
    //設置 迷你豬 造型
    setPixmap(QPixmap(":/pictures/piggy.png"));
    setPos(800,300);
    //設置定時器 使迷你豬 隨時間移動
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(25);
}

void Bullet2::move()
{
    setPos(x()-10,y());

    //迷你豬跑出豬圈時，kill!
    if(pos().x()<-400)
    {
       scene()->removeItem(this);
       delete this;
       game->score->decrease();
       return;
    }

    //game over 時，刪除移動中的迷你豬
    if(game->key2==2)
    {
       scene()->removeItem(this);
       delete this;
       return;
    }
}
