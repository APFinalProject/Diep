#include "square.h"

Square::Square()
{
    setPixmap(QPixmap(":/image/square.png"));
    int rand1=qrand()%743;
    int rand2=qrand()%543;
    this->setPos(rand1,rand2);
    health=4;
}
