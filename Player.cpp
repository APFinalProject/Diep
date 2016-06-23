#include "Player.h"
#include <QGraphicsPixmapItem>

Player::Player(){



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
            return;



}
