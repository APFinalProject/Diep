#ifndef OBJECT_H
#define OBJECT_H
#include<QGraphicsPixmapItem>
#include<QGraphicsItem>
class Object:public QGraphicsPixmapItem
{
public:
    Object();
    int health;
};

#endif // OBJECT_H
