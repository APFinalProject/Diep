#include "triangle.h"

Triangle::Triangle()
{
     setPixmap(QPixmap(":/image/triangle.png"));
     int rand1=rand()%720;
     int rand2=rand()%528;
     setPos(rand1,rand2);
     TRhealth=new Health();
     TRhealth->setHealth(3);
}
