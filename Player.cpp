#include "Player.h"
#include <QGraphicsPixmapItem>
#include <game.h>
#include <qmath.h>
#include <math.h>
#include "bullet.h"
#include <QList>
#include <typeinfo>
#include "square.h"
#include "triangle.h"
#include "pentagon.h"
extern Game * game;
Player::Player(){
    p_health=new Health();
    p_health->setHealth(8);
    setPixmap(QPixmap(":/pic1/tank (2).png"));
    QTimer * timer=new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(collide_player()));
    timer->start(2000);

}
void Player::collide_player(){
    QList<QGraphicsItem*> items=collidingItems();
    for (int i=0,n=items.size();i<n;++i){
        if(typeid(*(items[i]))== typeid(Square) ||typeid(*(items[i]))==typeid(Triangle)||typeid(*(items[i]))==typeid(Pentagon)){
            // decrease the health of the player
            Player().p_health->decrease ();

        }
    }
    return;
}
void Player::keyPressEvent(QKeyEvent * event){
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
            else if(event->key()==Qt::Key_Z){
                setTransformOriginPoint(pixmap().width()/2,pixmap().height()*2/3);
                setRotation(rotation()-20);
            }

            else if(event->key()==Qt::Key_X){
                setTransformOriginPoint(pixmap().width()/2,pixmap().height()*2/3);
               setRotation(rotation()+20);
            }
            else if(event->key() == Qt::Key_V)
                {
                    Bullet *bullet = new Bullet();



                    if(fmod(rotation(), 360)<=0 && fmod(rotation(), 360)>-90
                            || fmod(rotation(), 360)>=270 && fmod(rotation(), 360)<360)
                        bullet->setPos(x()+ pixmap().width()/2 - bullet->pixmap().width()/3 + (( pixmap().height()*2/3/9)*(fmod(rotation(), 90)/10))
                                   , y()- bullet->pixmap().height()/2 - (( pixmap().height()*2/3/9)*(fmod(rotation(), 90)/10)) );

                    else if(fmod(rotation(), 360)<=-90 && fmod(rotation(), 360)>-180
                            || fmod(rotation(), 360)>=180 && fmod(rotation(), 360)<270)
                        bullet->setPos(x()- pixmap().width()/2 - bullet->pixmap().width()/3 - (( pixmap().height()*2/3/9)*(fmod(rotation(), 90)/10))
                                       , y()+ bullet->pixmap().height()/2 - (( pixmap().height()*2/3/9)*(fmod(rotation(), 180)/10)));

                    else if(fmod(rotation(), 360)>=90 && fmod(rotation(), 360)<180
                            || fmod(rotation(), 360)<=-180 && fmod(rotation(), 360)>-270)
                        bullet->setPos(x()+ pixmap().width()/2 + bullet->pixmap().width()/3 - ((pixmap().height()*2/3/8.5)*(fmod(rotation(), 90)/10))
                                       , y()+pixmap().height());

                    else if(fmod(rotation(), 360)>=0 && fmod(rotation(), 360)<90
                            || fmod(rotation(), 360)<=-270 && fmod(rotation(), 360)>-360)
                        bullet->setPos(x()+ pixmap().width()/3 - bullet->pixmap().width()/2 - (( pixmap().height()*2/3/9)*(fmod(rotation(), 90)/10))
                                       , y()- bullet->pixmap().height()/2 - (( pixmap().height()*2/3/9)*((fmod(rotation(), 90)/10))));

                    scene()->addItem(bullet);


            }
            return;



}
