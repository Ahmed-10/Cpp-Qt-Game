#include <QGraphicsScene>
#include "MyRect.h"
#include "bullet.h"
#include "enemy.h"
#include <QDebug>

MyRect::MyRect(QGraphicsItem *parent) : QGraphicsRectItem(parent)
{
    bullet_sound = new QMediaPlayer();
    bullet_sound->setMedia(QUrl("qrc:/sounds/sounds/bullet.wav"));
}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0)
            setPos(x() - 10, y());
    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x() + 100 < 800)
            setPos(x() + 10, y());
    }

    else if(event->key() == Qt::Key_Space){
        Bullet * bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);

        if(bullet_sound->state() == QMediaPlayer::PlayingState){
            bullet_sound->setPosition(0);
        }
        else if(bullet_sound->state() == QMediaPlayer::StoppedState){
            bullet_sound->play();
        }

    }

}

void MyRect::spawn()
{
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);
}
