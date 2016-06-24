#include "square.h"

Square::Square()
{
    setPixmap(QPixmap(":/images/Square.png"));
    int rand1=qrand()%720;
    int rand2=qrand()%528;
    this->setPos(rand1,rand2);
}
