#include "square.h"

Square::Square()
{
    setPixmap(QPixmap(":/image/square.png"));
    int rand1=qrand()%720;
    int rand2=qrand()%528;
    this->setPos(rand1,rand2);
    SQhealth =new Health();
    SQhealth->setHealth(4);
}
