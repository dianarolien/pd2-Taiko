#ifndef BOTTOM_H
#define BOTTOM_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QMediaPlayer>

class Bottom: public QObject, public QGraphicsPixmapItem
{
     Q_OBJECT
public:
    Bottom();
    void keyPressEvent(QKeyEvent * event);
private:
    QTimer * timer;
    QMediaPlayer * pigsound ;
    QMediaPlayer * pigsound2 ;
public slots:
    void col();
};

#endif // BOTTOM_H
