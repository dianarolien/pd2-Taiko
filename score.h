#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem
{
public:
    Score(QGraphicsTextItem * parent = 0);
    void increase();
    void increase2();
    void decrease();
    int getScore();
    void initial();
private:
    int score;
};

#endif // SCORE_H
