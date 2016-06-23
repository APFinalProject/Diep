#include "rectangle.h"

Rectangle::Rectangle()
{
    setPixmap(QPixmap(":/images/Rectangle.png"));
    //choose a location randomly
    //set this size to not to go outside of bounds
    int rand1=rand()%720;
    int rand2=rand()%528;
    this->setPos(rand1,rand2);
}
