#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem* parent = nullptr);

    int get_score() { return _score; }
    void increase_score();
private:
    int _score;
};

#endif // SCORE_H
