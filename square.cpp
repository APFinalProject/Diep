#include "square.h"

Square::Square()
{
    setPixmap(QPixmap(":/images/Square.png"));
    int rand1=qrand()%743;
    int rand2=qrand()%543;
    this->setPos(rand1,rand2);
}
