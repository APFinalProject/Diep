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
            if(typeid(*(itemList[i])) == typeid(Triangle)|| typeid(*(itemList[i])) == typeid(Square) || typeid(*(itemList[i])) == typeid(Pentagon) )
            {
                qDebug()<<"colliding";
                game->score->increase();

                if(typeid(*(itemList[i]))==typeid(Square)){
                   if (Square().SQhealth->get_health()==4){
                        Square().SQhealth->setHealth(3);
                        qDebug()<<Square().SQhealth->health;
                    }
                    else if (Square().SQhealth->get_health()==3){
                        Square().SQhealth->setHealth(2);
                        qDebug()<<Square().SQhealth->health;
                    }
                    else if (Square().SQhealth->get_health()==2){
                        Square().SQhealth->setHealth(1);
                        qDebug()<<Square().SQhealth->health;
                    }
                    else if (Square().SQhealth->get_health()==1){
                        Square().SQhealth->setHealth(0);
                        qDebug()<<Square().SQhealth->health;
                    }
                   else if (Square().SQhealth->get_health()==0){
                       qDebug()<<Square().SQhealth->health;
                       scene()->removeItem(itemList[i]);
                       scene()->removeItem(this);
                       delete itemList[i];
                       delete this;
                   }
                                }
                                else if(typeid(*(itemList[i]))==typeid(Triangle)){
                                    Triangle().TRhealth->decrease();
                                }
                                else {
                                    Pentagon().PEhealth->decrease();
                                    qDebug()<<Pentagon().PEhealth->get_health();
                                }
                if(typeid(*(itemList[i]))==typeid(Square) &&Square().SQhealth->get_health()==0)
                                {

                                    scene()->removeItem(itemList[i]);
                                    scene()->removeItem(this);
                                    delete itemList[i];
                                    delete this;
                                }
                                else if(typeid(*(itemList[i]))==typeid(Triangle) && Triangle().TRhealth->get_health()==0)
                                {

                                    scene()->removeItem(itemList[i]);
                                    scene()->removeItem(this);
                                    delete itemList[i];
                                    delete this;
                                }
                                else if(typeid(*(itemList[i]))==typeid(Pentagon) && Pentagon().PEhealth->get_health()==0)
                                {

                                    scene()->removeItem(itemList[i]);
                                    scene()->removeItem(this);
                                    delete itemList[i];
                                    delete this;
                                }
                return;
            }
        }


    if(pos().y() < 0)
    {
        //scene()->removeItem(this);
        delete this;
    }
}
