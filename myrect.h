#ifndef MYRECT_H
#define MYRECT_H
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>

class Myrect: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
    public:
       Myrect();
       void timer1();
    public slots:
       void setBullet();
    private:
       QTimer * timer;

};

#endif // MYRECT_H
