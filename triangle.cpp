#include "triangle.h"

Triangle::Triangle()
{
     setPixmap(QPixmap(":/image/triangle.png"));
     int rand1=rand()%757;
     int rand2=rand()%551;
     setPos(rand1,rand2);
     health=3;
}
