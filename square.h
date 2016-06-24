#ifndef SQUARE_H
#define SQUARE_H

#include"object.h"
#include"health.h"
class Square:public Object
{
public:
    Square();
    Health * SQhealth;
};

#endif // SQUARE_H
