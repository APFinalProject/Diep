#include "rectangle.h"

Rectangle::Rectangle()
{
    setPixmap(QPixmap(":/images/Rectangle.png"));
    int rand1=rand()%800;
    int rand2=rand()%600;
    this->setPos(rand1,rand2);
}
