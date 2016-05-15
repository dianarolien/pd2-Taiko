#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsView>
#include "bullet.h"
#include "myrect.h"
#include "bottom.h"
#include "score.h"
#include "fri.h"
#include "dialog.h"
#include "bullet2.h"

class Game: public QGraphicsView
{
    public:
        Game(QWidget * parent = 0);
        QGraphicsScene * scene;
        Myrect * rect;
        Bullet * bullet;
        Bullet2 *bullet2;
        Score * score;
        Bottom * bottom;
        Fri * fri;
        Dialog * dialog;
        int key ;
        int key2;
};

#endif // GAME_H
