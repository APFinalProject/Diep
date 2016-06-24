#include "triangle.h"

Triangle::Triangle()
{
     setPixmap(QPixmap(":/images/Triangle.png"));
     int rand1=rand()%757;
     int rand2=rand()%559;
     this->setPos(rand1,rand2);
}

