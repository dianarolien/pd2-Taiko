#include "fri.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "dialog.h"

Fri::Fri()
{
    time = new Time();
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Time_decrease()));
    timer->start(1000);
}

void Fri::Time_decrease()
{
    time->print();

}
