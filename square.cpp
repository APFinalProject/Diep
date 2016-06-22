#include "square.h"

Square::Square()
{
    setPixmap(QPixmap(":/images/Square.png"));
    int rand1=qrand()%800;
    int rand2=qrand()%600;
    this->setPos(rand1,rand2);
}
