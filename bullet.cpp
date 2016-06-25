#include "bullet.h"
#include <QTimer>
#include <qmath.h>
#include <QtMath>
#include <QDebug>
#include <QtMath>
#include <QList>
#include <QGraphicsItem>
#include <typeinfo>
#include "game.h"
#include "player.h"
#include "score.h"
#include "triangle.h"
#include "square.h"
#include "pentagon.h"

extern Game * game;
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
    float degrees;
    float radians;

    if(game->player->rotation()<0)
    {
        degrees = -fmod(game->player->rotation() , 360)+90;
        radians = qDegreesToRadians(degrees);
    }
    else
    {
        degrees = 90-fmod(game->player->rotation() , 360);
        radians = qDegreesToRadians(degrees);
    }
    if(degrees>=90 && degrees<270)
        setPos(x()-5, y()+(qTan(radians)*5));
    else
        setPos(x()+5, y()-(qTan(radians)*5));

    QList <QGraphicsItem *> itemList = collidingItems();
        for(int i=0 ;i < itemList.size();i++)
        {
            if(typeid(*(itemList[i])) == typeid(Triangle)
                    || typeid(*(itemList[i])) == typeid(Square) || typeid(*(itemList[i])) == typeid(Pentagon) )
            {
                qDebug()<<"colliding";
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
