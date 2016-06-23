#include "bullet.h"
#include <QTimer>


Bullet::Bullet(QObject *parent) :
    QObject(parent)
{
    //creat bullet
    setPixmap(QPixmap(":/image/bullet.png"));
    setScale(0.5);
    //set timer to move bullet
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(20);
}

void Bullet::move()
{
    setPos(x()+10,y()+10);
    if(pos().y() < 0)
    {
        //scene()->removeItem(this);
        delete this;
    }
}
