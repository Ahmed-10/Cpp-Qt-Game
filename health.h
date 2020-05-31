#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
public:
    Health(QGraphicsItem* parent = nullptr);

    int get_health() { return _health; }
    void decrease_health();
private:
    int _health;
};

#endif // HEALTH_H
