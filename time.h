#ifndef TIME_H
#define TIME_H
#include <QGraphicsTextItem>

class Time: public QGraphicsTextItem
{
public:
    Time(QGraphicsTextItem * parent = 0);
    void print();
    int time1;
};

#endif // TIME_H
