#ifndef TRIANGLE_H
#define TRIANGLE_H

#include"object.h"
#include"health.h"
class Triangle:public Object
{
public:
    Triangle();
    Health * TRhealth;
};

#endif // TRIANGLE_H
