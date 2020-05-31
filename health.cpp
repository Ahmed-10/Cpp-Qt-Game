#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    _health = 3;

    setPlainText(QString("health: ") + QString::number(_health));

    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));

}

void Health::decrease_health()
{
    _health--;
    setPlainText(QString("health: ") + QString::number(_health));
}
