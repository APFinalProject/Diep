#include "health.h"
#include <game.h>

extern Game * game;
Health::Health(int i_health,QGraphicsItem * parent ):QGraphicsTextItem(parent)
{
    //initialize healt for instance 5
    health = i_health;
    //draw the text
    setPlainText(QString("Health:"+ QString::number(health)));
    //set the color of the text
    setDefaultTextColor(Qt::blue);
    // set the font of the text
    setFont(QFont("times",16));
}
void Health::decrease()
{
    health--;
    setPlainText(QString("Health:"+ QString::number(health)));
}

void Health::setHealth(int i_health)
{
    health = i_health;
}
