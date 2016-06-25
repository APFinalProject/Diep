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
    //startt=new Button(":/image/3play.png");
    //startt->setPos(scene->width()/2,scene->height()/2);
    //scene->addItem(startt);
    scene = new QGraphicsScene();
    setBackgroundBrush(QBrush(QImage(":/image/HEX.png")));
    setScene(scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    player = new Player();
    scene->addItem(player);
    //int x1=player->set;
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    //enemy=new Enemy();
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

void Game::gameover(){
           restartt=new Button(":/image1/1rep.png");
           restartt->setPos(scene->width()/4,scene->height()/2);
           restartt->setScale(0.5);
           scene->addItem(restartt);
           QTimer * timer=new QTimer();
           QObject::connect(timer,SIGNAL(clicked()),this,SLOT(restart()));
           timer->start(2000);


           quitt=new Button(":/image2/2close.png");
           quitt->setScale(0.5);
           quitt->setPos(scene->width()*3/4,scene->height()/2);
           scene->addItem(quitt);
           QTimer * timer1=new QTimer();
           QObject::connect(timer1,SIGNAL(clicked()),this,SLOT(close()));
            timer1->start(2000);

}
void Game::restart(){
           scene->removeItem(score);
           delete score;
           scene->removeItem(health);
           delete health;
           scene->removeItem(player);
           delete player;




           scene->addItem(score);
           scene->addItem(health);
           health->setPos(health->x(),health->y()+25);
           scene->addItem(player);
           player->setPos(400,500);
           player->setFlag(QGraphicsItem::ItemIsFocusable);
           player->setFocus();

           //create a timer for Create Function
           QTimer * timer=new QTimer();
           //connect a signal to slot for create
           QObject::connect(timer,SIGNAL(timeout()),this,SLOT(create()));
           timer->start(10000);
}
void Game::start(){


    //create a player
    player=new Player();
    player->setPos(400,500);

    //add the player to the scene
    scene->addItem(player);
    //make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //create a timer for Create Function
    QTimer * timer=new QTimer();
    //connect a signal to slot for create
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(create()));
    timer->start(10000);

    //create the score / health
    score= new Score();
    scene->addItem(score);
    health= new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);


    //adding music to the background
    /*QMediaplayer * music=new QMediaplayer();
    music->setmedia(QUrl("*qrc:/music/Game-Menu.mp3"));
    music->play();
}

void Game::menu(){
    startt = new Button(QString(":/image/3play.png"));
    startt->setPos(300,400);
    scene->addItem(startt);
    QTimer * timer2=new QTimer();
    QObject::connect(timer2,SIGNAL(clicked()),this,SLOT(start()));
    timer2->start(2000);
}

