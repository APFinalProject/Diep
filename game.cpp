#include "game.h"
#include <QGraphicsRectItem>
#include "triangle.h"
#include"stdlib.h"
#include <QTimer>
#include <QDebug>
#include <QObject>
#include "pentagon.h"
#include "button.h"

Game::Game(QWidget * parent):QGraphicsView(parent)
{
    startt=new Button(":/image/3play.png");
    startt->setPos(scene->width()/2,scene->height()/2);
    scene->addItem(startt);

    //create a scene
    scene= new QGraphicsScene();
    setScene(scene);
    scene->setSceneRect(0,0,800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    show();



}
void Game::menu(){
    startt = new Button(QString(":/image/3play.png"));
    start->setPos(300,400);
    scene->addItem(startt);
    connect(play,SIGNAL(clicked()),this,SLOT(start()));
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
    QMediaplayer * music=new QMediaplayer();
    music->setmedia(QUrl("*qrc:/music/Game-Menu.mp3"));
    music->play();

}
       void Game::gameover(){
           restartt=new Button(":/image1/1rep.png");
           restartt->setPos(scene->width()/4,scene->height()/2);
           restartt->setScale(0.5);
           scene->addItem(restartt);
           connect(timer,SIGNAL(clicked()),this,SLOT(restart()));



           quitt=new Button(":/image2/2close.png");
           quitt->setScale(0.5);
           quitt->setPos(scene->width()*3/4,scene->height()/2);
           scene->addItem(quitt);
           connect(timer,SIGNAL(clicked()),this,SLOT(close()));


    }
       void Game::restartt(){
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







void Game::create(){
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
