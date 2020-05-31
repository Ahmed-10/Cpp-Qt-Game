#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>

#include "MyRect.h"
#include "score.h"
#include "health.h"

class Game: public QGraphicsView{
public:
    Game();

    QGraphicsScene * scene;
    MyRect * player;
    Score* score;
    Health* health;
};

#endif // GAME_H
