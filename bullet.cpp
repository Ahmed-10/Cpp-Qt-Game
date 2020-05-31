#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>

#include "game.h"

extern Game* game;

Bullet::Bullet()
{
    setRect(0, 0, 10, 50);

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    QList<QGraphicsItem*> colliding_items = collidingItems();

    int size = colliding_items.size();
    for(int i = 0; i < size; i++){
        if(typeid (*(colliding_items[i])) == typeid (Enemy)){
            game->score->increase_score();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;

            return;
        }
    }

    setPos(x(), y() - 10);

    if(pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}

