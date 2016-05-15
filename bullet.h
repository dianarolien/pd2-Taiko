#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>

class Bullet: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    public:
        Bullet();
    public slots:
        void move();

};

#endif // BULLET_H
