#include "rectangle.h"

Rectangle::Rectangle()
{
    setPixmap(QPixmap(":/images/Rectangle.png"));
    int rand1=rand()%720;
    int rand2=rand()%528;
    this->setPos(rand1,rand2);
}
