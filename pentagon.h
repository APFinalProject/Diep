#ifndef PENTAGON_H
#define PENTAGON_H

#include"object.h"
#include"health.h"
class Pentagon :public Object
{
public:
    Pentagon();
    Health * PEhealth;
};

#endif // PENTAGON_H
