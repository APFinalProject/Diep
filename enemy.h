#ifndef ENEMY_H
#define ENEMY_H
#include"triangle.h"
#include"rectangle.h"
#include"square.h"
class Enemy:public QObject,public QGraphicsPixmapItem
{
private:
    Q_OBJECT
public:
    Enemy();
    void Create();
};

#endif // ENEMY_H
