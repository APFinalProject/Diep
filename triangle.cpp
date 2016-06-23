#include "triangle.h"

Triangle::Triangle()
{
     setPixmap(QPixmap(":/images/Triangle.png"));
     int rand1=rand()%720;
     int rand2=rand()%528;
     this->setPos(rand1,rand2);
}

