#include "time.h"
#include <QFont>
#include <QTimer>
#include "dialog.h"
#include "game.h"
#include <QDebug>

extern Game *game;

//計時器
Time::Time(QGraphicsTextItem *parent)
{
    time1 = 30;
    setPlainText(QString("Time:"+QString::number(time1)));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",30));
    setPos(-400,45);

}

void Time::print()
{
    if(time1!=0)
        time1--;
    setPlainText(QString("Time:"+QString::number(time1)));
    if(game->key2==1)
    {
        game->key2 =0;
        time1 = 30;
        setPlainText(QString("Time:"+QString::number(time1)));
    }
    if(time1==0 && game->key2 != 2 )
    {
        Dialog  * dialog = new Dialog();
        dialog->show();
        game->key2 = 2;
    }
    if(game->score->getScore()<0 && game->key2 != 2 )
    {
        Dialog  * dialog = new Dialog();
        dialog->show();
        game->key2 = 2;
    }
}

