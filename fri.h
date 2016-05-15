#ifndef FRI_H
#define FRI_H
#include <QGraphicsRectItem>
#include <QObject>
#include "time.h"

class Fri: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Fri();
    Time * time;

public slots:
    void Time_decrease();

};

#endif // FRI_H
