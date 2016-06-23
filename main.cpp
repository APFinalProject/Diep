#include <QtGui/QApplication>
#include "Player.h"
#include <qgraphicsview>
#include <QGraphicsScene>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //create a scene
    QGraphicsScene * scene= new QGraphicsScene();
    //create an item to add into the scene

    Player * item= new Player();
    item->setPixmap(QPixmap(":/pic1/tank (2).png"));


    //put the item into the scene
    scene->addItem(item);
    item->setFlag(QGraphicsItem::ItemIsFocusable);
    item->setFocus();

    //create a view
    QGraphicsView * view =new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);



    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    item->setPos(view->width()/2 , view->height()-item->pixmap().height());
    view->show();

    return a.exec();
}
