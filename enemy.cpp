#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <stdlib.h>

#include "game.h"

extern Game* game;

Enemy::Enemy()
{
    int random_num = rand() % 700;
    setPos(random_num, 0);
    setRect(0, 0, 100, 100);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    setPos(x(), y() + 5);

    if(pos().y() > 600){
        game->health->decrease_health();

        scene()->removeItem(this);
        delete this;
        qDebug() << "deleted";
    }
}
