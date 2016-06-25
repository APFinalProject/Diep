#include "player.h"
#include "bullet.h"
#include <QDebug>
#include <qmath.h>
#include <QGraphicsScene>
#include <math.h>
#include <QTimer>
#include "game.h"
#include "score.h"
#include "triangle.h"
#include "square.h"
#include "pentagon.h"
#include <QList>
#include <QGraphicsItem>
#include <typeinfo>

extern Game *game;
Player::Player(QObject *parent):QObject(parent)
{
    setPixmap(QPixmap(":/image/tank.png"));
    setPos(400,300);
    //creat timer and connect for shooting the bullets
    QTimer * shoot_timer=new QTimer();
    QObject::connect(shoot_timer,SIGNAL(timeout()),this,SLOT(collide_player()));
    shoot_timer->start(200);
    //creat timer and connect too delete the bullets
    QTimer * delete_timer=new QTimer();
    QObject::connect(delete_timer,SIGNAL(timeout()),this,SLOT(delete_bullets()));
    delete_timer->start(1000);
}
void Player::collide_player(){

    QList<QGraphicsItem*> items=collidingItems();
    for (int i=0,n=items.size();i<n;++i){
        if(typeid(*(items[i]))== typeid(Square) ||typeid(*(items[i]))==typeid(Triangle)||typeid(*(items[i]))==typeid(Pentagon)){
            // decrease the health of the player
            game->health->decrease();
        }
    }
    return;
}

void Player::delete_bullets()
{
    for(int i=0;i<v_bullet.size();i++)
    {
        //qDebug()<<"remove";
        scene()->removeItem(v_bullet[i]);
        //v_bullet.remove(i);
        //delete v_bullet[i];
    }
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(pos().x()>0)
        setPos(x()-10,y());
    }
    else if(event->key() == Qt::Key_Right)
    {

        if(x()+pixmap().width()<800)
        setPos(x()+10,y());
    }
    else if(event->key() == Qt::Key_Up)
    {
        if(pos().y()>0)
        setPos(x(),y()-10);
    }
    else if(event->key() == Qt::Key_Down)
    {
        if(y()+pixmap().height()<600)
        setPos(x(),y()+10);
    }

    else if(event->key() == Qt::Key_Shift)
    {
        Bullet *bullet = new Bullet();
        v_bullet.push_back(bullet);
        float degrees=0.0;
        float radians=0.0;

        if(rotation()<0)
        {
            degrees = -fmod(rotation() , 360)+90;
            radians = qDegreesToRadians(degrees);
        }
        else
        {
            degrees = 90-fmod(rotation() , 360);
            radians = qDegreesToRadians(degrees);
        }

        degrees = fmod(degrees,360);
        //qDebug()<<degrees;
        //qDebug()<<bullet->x()<<bullet->y();


        //0-2bullet->setPos(x()+28-14 +(qCos(radians)* 51),y()-28 + ((1-qSin(radians))* 51));
        //3-6bullet->setPos(x()+28-21 +(qCos(radians)* 51),y()-21 + ((1-qSin(radians))* 51));
        //7-9bullet->setPos(x()+28-26 +(qCos(radians)* 51),y()-14 + ((1-qSin(radians))* 51));
        //bullet->setPos(x()+28-21 +(qCos(radians)* 51),y()-7 + ((1-qSin(radians))* 51));
        //bullet->setPos(x()+28-14 +(qCos(radians)* 51),y() + ((1-qSin(radians))* 51));
        if(degrees>=90 && degrees<120 || degrees>-270 && degrees<-240)
            bullet->setPos(x()+28-14 +(qCos(radians)* 51),y()-28 + ((1-qSin(radians))* 51));
        else if(degrees>=120 && degrees<160 ||degrees>=-240 && degrees<-200)
            bullet->setPos(x()+28-21 +(qCos(radians)* 51),y()-21 + ((1-qSin(radians))* 51));
        else if(degrees>=160 && degrees<190 || degrees>=-200 && degrees<-170 )
            bullet->setPos(x()+28-26 +(qCos(radians)* 51),y()-14 + ((1-qSin(radians))* 51));
        else if(degrees>=190 && degrees<230 || degrees>=-170 && degrees<-130 )
            bullet->setPos(x()+28-21 +(qCos(radians)* 51),y()-7 + ((1-qSin(radians))* 51));
        else if(degrees>=230 && degrees<270 || degrees>=-130 && degrees<-90 )
            bullet->setPos(x()+28-14 +(qCos(radians)* 51),y() + ((1-qSin(radians))* 51));
        else if(degrees>=270 && degrees<300 || degrees>=-90 && degrees<-60)
            bullet->setPos(x()+28-7 +(qCos(radians)* 51),y() + ((1-qSin(radians))* 51));
        else if(degrees>=300 && degrees<340 || degrees>=-60 && degrees<-20 )
            bullet->setPos(x()+28 +(qCos(radians)* 51),y()-7 + ((1-qSin(radians))* 51));
        else if(degrees>=340 && degrees<360 || degrees>=-20 && degrees<0 )
            bullet->setPos(x()+20 +7+(qCos(radians)* 51),y()-14 + ((1-qSin(radians))* 51));
        else if(degrees>=0 && degrees<50)
            bullet->setPos(x()+14+14 +(qCos(radians)* 51),y()-21 + ((1-qSin(radians))* 51));
        else if(degrees>=50 && degrees<90)
            bullet->setPos(x()+14+14 +(qCos(radians)* 51),y()-21 + ((1-qSin(radians))* 51));
        scene()->addItem(bullet);
    }
    else if(event->key() == Qt::Key_Z)
    {
        setTransformOriginPoint(28 , 51);
        setRotation(rotation()-10);
        qDebug() <<rotation() ;

    }
    else if(event->key() == Qt::Key_X)
    {
        setTransformOriginPoint(28 , 51);
        setRotation(rotation()+10);
        qDebug() <<rotation() ;
    }
    return;

}

