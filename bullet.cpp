#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include "bottom.h"
#include "score.h"
#include "game.h"
#include <QDebug>
#include <QGraphicsItem>

extern Game * game;

Bullet::Bullet()
{
    //設置 炸豬排 造型
    setPixmap(QPixmap(":/pictures/pig.png"));
    setPos(800,300);
     //設置定時器 使炸豬排 隨時間移動
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(25);

}

void Bullet::move()
{
    setPos(x()-6,y());

    //炸豬排跑出豬圈時，kill!
    if(pos().x()<-400)
    {
       scene()->removeItem(this);
       delete this;
       game->score->decrease();
       return;
    }

    //game over 時，刪除移動中的炸豬排
    if(game->key2==2)
    {
       scene()->removeItem(this);
       delete this;
       return;
    }
}
