#include "bottom.h"
#include <QKeyEvent>
#include "game.h"
#include <QDebug>
#include <QList>
#include <typeinfo>
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>

extern Game *game;

Bottom::Bottom()
{
    setPixmap(QPixmap(":/pictures/car.png"));
    setPos(-250,280);
    pigsound = new QMediaPlayer();
    pigsound->setMedia(QUrl("qrc:/sounds/1722.mp3"));
    pigsound2 = new QMediaPlayer();
    pigsound2->setMedia(QUrl("qrc:/sounds/1722.mp3"));
}

void Bottom::keyPressEvent(QKeyEvent * event)
{
    if(event->key() != Qt::Key_H && event->key() != Qt::Key_D)
        return;
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(col()));
    if(event->key() == Qt::Key_D)
        game->key = 1;
    if(event->key() == Qt::Key_H)
        game->key = 2;
    timer->start(100);
    return ;
}

void Bottom::col()
{
    QList<QGraphicsItem *>colliding_items2 = collidingItems();
    {
        for(int i=0,n =colliding_items2.size();i<n;i++)
        {
            if(typeid(*(colliding_items2[i])) == typeid(Bullet2)&&game->key==2)
            {
                scene()->removeItem(colliding_items2[i]);
                game->score->increase2();
                delete colliding_items2[i];
                game->key = 0;
                timer->stop();
                pigsound2->play();
                return;
            }
        }
    }
    QList<QGraphicsItem *>colliding_items = collidingItems();
    {
        for(int i=0,n =colliding_items.size();i<n;i++)
        {
            if(typeid(*(colliding_items[i])) == typeid(Bullet)&&game->key==1)
            {
                scene()->removeItem(colliding_items[i]);
                game->score->increase();
                delete colliding_items[i];
                game->key = 0;
                timer->stop();
                pigsound->play();
                return;
            }
        }
    }

    game->key = 0;
    timer->stop();
    game->score->decrease();
    return;
}
