#include "game.h"
#include <QGraphicsRectItem>
#include "triangle.h"
#include"stdlib.h"
#include <QTimer>
#include <QDebug>
#include <QObject>
#include "pentagon.h"


Game::Game(QWidget *parent):
    QGraphicsView(parent)
{
    scene = new QGraphicsScene();

    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    player = new Player();
    scene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //create a Qtimer
    QTimer * timer = new QTimer();
    //connect a signal to slot for create
    QObject::connect(timer,SIGNAL(timeout()) , this , SLOT(create()));
    timer->start(5000);

    score = new Score();
    scene->addItem(score);

    health = new  Health(8);
    health->setPos(x(),y()+25);
    scene->addItem(health);



    show();

    setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
}

void Game::create()
{
    qDebug()<<"aaaaaaa";
    //choose one of the shapes that inherits from object randomly and show it
    int rnumber1=rand()%3;
    if(rnumber1==1){
        Pentagon * pen=new Pentagon();
        scene->addItem(pen);
    }
    else if(rnumber1==2){
        Square * squ=new Square();
        scene->addItem(squ);
    }
    else{
        Triangle * tri=new Triangle();
        scene->addItem(tri);
    }

}
