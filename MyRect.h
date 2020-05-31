#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#include <QMediaPlayer>

class MyRect: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    MyRect(QGraphicsItem* parent = nullptr);
    void keyPressEvent(QKeyEvent * event);

public slots:
    void spawn();

private:
    QMediaPlayer * bullet_sound;
};

#endif // MYRECT_H
