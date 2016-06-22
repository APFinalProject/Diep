#include <QtGui/QApplication>
#include<QGraphicsView>
#include<QGraphicsScene>
//#include<QGraphicsItem>
//#include<QGraphicsPixmapItem>
#include"object.h"
#include"triangle.h"
#include"rectangle.h"
#include"square.h"
#include"enemy.h"
#include <QObject>
#include <QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView * view=new QGraphicsView;
    QGraphicsScene * scene=new QGraphicsScene;
    Enemy * player;
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    view->setScene(scene);
    scene->addItem(player);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(800,600);
    QTimer * timer = new QTimer();
    int i = 2000;
    QObject::connect(timer , SIGNAL(timeout()),player, SLOT(Create()));
    timer->start(i);
    view->show();
    return a.exec();
}
