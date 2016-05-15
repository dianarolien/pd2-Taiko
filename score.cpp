#include "score.h"
#include <QGraphicsTextItem>
#include <QFont>

Score::Score(QGraphicsTextItem *parent)
{
    score = 0;
    setPlainText(QString("Score:"+QString::number(score)));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",30));
    setPos(-400,10);
}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: ")+QString::number(score));
}

void Score::increase2()
{
    score = score+2;
    setPlainText(QString("Score: ")+QString::number(score));
}

void Score::decrease()
{
    score--;
    setPlainText(QString("Score: ")+QString::number(score));
}

int Score::getScore()
{
    return score;
}

void Score::initial()
{
    score = 0 ;
    setPlainText(QString("Score: ")+QString::number(score));
}
