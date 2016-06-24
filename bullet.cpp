#include "bullet.h"
#include"game.h"
#include "player.h"

extern Game * game;
Bullet::Bullet(QObject *parent) :
    QObject(parent)
{
    //creat bullet
    setPixmap(QPixmap(":/images/bullet.png"));
    setScale(0.5);
    //set timer to move bullet
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(20);
}

void Bullet::move()
{
    setPos(x()+10,y()+10);
    QList<QGraphicsItem *> itemList = collidingItems();
    for(int i=0 ;i < itemList.size();i++)
    {
        if(typeid(*(itemList[i])) == typeid(Player))
        {
            game->score->increase();

            scene()->removeItem(itemList[i]);
            scene()->removeItem(this);

            delete itemList[i];
            delete this;
            return;
        }
    }
    if(pos().y() < 0)
    {
        //scene()->removeItem(this);
        delete this;
    }
}
