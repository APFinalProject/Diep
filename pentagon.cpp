#include "pentagon.h"
#include<stdlib.h>
pentagon::pentagon()
{
    setPixmap(QPixmap(":/images/pentagon.png"));
    int rand1=rand()%749;
    int rand2=rand()%550;
    this->setPos(rand1,rand2);
}
