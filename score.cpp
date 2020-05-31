#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    _score = 0;

    setPlainText(QString("score: ") + QString::number(_score));

    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));

}

void Score::increase_score()
{
    _score++;
    setPlainText(QString("score: ") + QString::number(_score));
}
