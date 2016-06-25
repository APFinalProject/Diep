#include "bullet.h"
#include <QTimer>
#include <qmath.h>
#include <QtMath>
#include <QDebug>
#include <QList>
#include <QGraphicsItem>
#include <typeinfo>
#include "game.h"
#include "player.h"
#include "score.h"
#include "triangle.h"
#include "square.h"
#include "object.h"
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
    //move with rotation of tank
    //convert degrees to radians
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
    //move bullet
    if(degrees==90)
        setPos(x(),y()-5);
    else if(degrees==270)
        setPos(x(),y()+5);
    else if(degrees>90 && degrees<270)
        setPos(x()-5, y()+(qTan(radians)*5));
    else if(degrees>270 && degrees<90)
        setPos(x()+5, y()-(qTan(radians)*5));
    //colliding bullet with objects
    QList<QGraphicsItem *> items = collidingItems();
            for(int i=0 ; i<items.size() ;i++)
            {
                if(typeid(*(items[i]))==typeid(Square)){
                    QVector<Object *>::Iterator it = game->objects.begin();
                    for(int j=0 ; j<game->objects.size() ;j++)
                    {
                        if(game->objects.at(j) == items[i])
                        {
                                if(game->objects.at(j)->health ==1)
                                {
                                    scene()->removeItem(items[i]);
                                    game->objects.erase(it+j);
                                }
                                else
                                {
                                    game->objects.at(j)->health--;
                                }
                        }

                    }
                                game->score->increase();
                                scene()->removeItem(this);
                                delete this;
                                return;

                }
                if(typeid(*(items[i]))==typeid(Triangle)){
                    QVector<Object *>::Iterator it = game->objects.begin();
                    for(int j=0 ; j<game->objects.size() ;j++)
                    {
                        if(game->objects.at(j) == items[i])
                        {
                                if(game->objects.at(j)->health ==1)
                                {
                                    scene()->removeItem(items[i]);
                                    game->objects.erase(it+j);
                                }
                                else
                                {
                                    game->objects.at(j)->health--;
                                }
                        }

                    }

                    game->score->increase();
                    scene()->removeItem(this);
                    delete this;
                    return;
                }
                if(typeid(*(items[i]))==typeid(Pentagon)){
                    QVector<Object *>::Iterator it = game->objects.begin();
                    for(int j=0 ; j<game->objects.size() ;j++)
                    {
                        if(game->objects.at(j) == items[i])
                        {
                                if(game->objects.at(j)->health ==1)
                                {
                                    scene()->removeItem(items[i]);
                                    game->objects.erase(it+j);
                                }
                                else
                                {
                                    game->objects.at(j)->health--;
                                }
                        }

                    }
                    game->score->increase();
                    scene()->removeItem(this);
                    delete this;
                    return;
                }
            }
            if(pos().y() < 0)
            {
                delete this;
            }
}
