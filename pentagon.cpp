#include "pentagon.h"

Pentagon::Pentagon()
{
    setPixmap(QPixmap(":/image/pentagon.png"));
        int rand1=rand()%749;
        int rand2=rand()%550;
        this->setPos(rand1,rand2);
        PEhealth=new Health();
        PEhealth->setHealth(5);
}
void Pentagon::Pdecrease(){
    PEhealth--;
}
