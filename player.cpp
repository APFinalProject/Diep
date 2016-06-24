#include "player.h"
#include "bullet.h"
#include <QDebug>
#include <qmath.h>
#include <QGraphicsScene>
#include <math.h>
//bullet->setPos(x()+ pixmap().width()/2 - bullet->pixmap().width()/3 + (( pixmap().height()*2/3/9)*(fmod(rotation(), 90)/10))
//, y()- bullet->pixmap().height()/2 + (( pixmap().height()*2/3/9)*(fmod(rotation(), 90)/10)));

Player::Player()
{
    setPixmap(QPixmap(":/image/tank.png"));

    setPos(400,300);
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

        qDebug() <<  x()<<y() ;

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
    else if(event->key() == Qt::Key_Z)
    {
        setTransformOriginPoint(pixmap().width()/2 , pixmap().height()*2/3);
        setRotation(rotation()-10);
        qDebug() <<rotation() ;

    }
    else if(event->key() == Qt::Key_X)
    {
        setTransformOriginPoint(pixmap().width()/2 , pixmap().height()*2/3);
        setRotation(rotation()+20);
        qDebug() <<rotation() ;
    }
    return;

}
