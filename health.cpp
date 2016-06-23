#include "health.h"
#include <game.h>

extern Game * game;
Health::Health(QGraphicsItem * parent):QGraphicsTextItem(parent)
{
    //initialize healt for instance 5
    health=5;
    //draw the text
    setPlainText(QString("Health:"+ QString::number(health)));
    //set the color of the text
    setDefaultTextColor(Qt::blue);
    // set the font of the text
    setFont(QFont("times",16));
}
void Health::decrease(){
    health--;
}
