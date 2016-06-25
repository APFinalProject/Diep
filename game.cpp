#include "game.h"
#include <QGraphicsRectItem>
#include "triangle.h"
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include <QObject>
#include "pentagon.h"
#include <QGraphicsTextItem>
#include <QImage>
Game::Game(QWidget *parent):
    QGraphicsView(parent)
{
    //create a scene
    scene = new QGraphicsScene();
    setBackgroundBrush(QBrush(QImage(":/image/HEX.png")));
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //create a player
    player = new Player();
    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    //create  a Qtimer
    QTimer * timer = new QTimer();
    //connect a signal to slot for create objects
    QObject::connect(timer,SIGNAL(timeout()) , this , SLOT(create()));
    timer->start(1000);
    //create  score
    score = new Score();
    scene->addItem(score);
    //create  health
    health = new Health();
    health->setPos(x(),y()+25);
    scene->addItem(health);

    show();

    setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
}
void Game::create()
{
    qDebug()<<"object";
    //choose one of the shapes that inherits from object randomly and show it
    int rnumber1=rand()%3;
    if(rnumber1==1){
        Pentagon * pen=new Pentagon();
        scene->addItem(pen);
        objects.push_back(pen);
    }
    else if(rnumber1==2){
        Square * squ=new Square();
        scene->addItem(squ);
        objects.push_back(squ);
    }
    else{
        Triangle * tri=new Triangle();
        scene->addItem(tri);
        objects.push_back(tri);
    }

}

