#include "triangle.h"

Triangle::Triangle()
{
     setPixmap(QPixmap(":/images/Triangle.png"));
     int rand1=rand()%800;
     int rand2=rand()%600;
     this->setPos(rand1,rand2);
}

