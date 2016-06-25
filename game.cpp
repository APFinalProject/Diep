#include "game.h"
#include <QGraphicsRectItem>
#include "triangle.h"
#include"stdlib.h"
#include <QTimer>
#include <QDebug>
#include <QObject>
#include "pentagon.h"
#include<QGraphicsTextItem>
#include<QImage>
Game::Game(QWidget *parent):
    QGraphicsView(parent)
{
    scene = new QGraphicsScene();
    setBackgroundBrush(QBrush(QImage(":/image/HEX.png")));
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
    timer->start(1000);

    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(x(),y()+25);
    scene->addItem(health);

    show();

    setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
}
/*
void Game::displayMainMenu()
{
    //create the title text
    QGraphicsTextItem *titleText=new QGraphicsTextItem(QString("HEX Wars"));
    QFont titlefont("comic sans",50);
    titleText->setFont(titlefont);
    int x2=this->width()/2-titleText->boundingRect().width()/2;
    int y2=150;
    titleText->setPos(x2,y2);
    scene->addItem(titleText);

    //create play button
    button * playbutton=new button(QString("play"));
    int xsBtn=this->width()/2-playbutton->boundingRect().width()/2;
    int ysBtn=275;
    playbutton->setPos(xsBtn,ysBtn);
    connect(playbutton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playbutton);

    //creat quit button
    button * quitbutton=new button(QString("quit"));
    int xqBtn=this->width()/2-quitbutton->boundingRect().width()/2;
    int yqBtn=350;
    connect(quitbutton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitbutton);
}
*/
void Game::create()
{
    qDebug()<<"object";
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

/*void Game::start()
{
    //clear the screen
    scene->clear();

}*/
