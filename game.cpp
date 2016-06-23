#include "game.h"
#include"stdlib.h"

Game::Game(QWidget * parent):QGraphicsView(parent)
{
    scene=new QGraphicsScene;
    setScene(scene);
    //scene->addItem(player);
    scene->setSceneRect(0,0,800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    
    setFixedSize(800,600);
    //create a Qtimer
    QTimer * timer = new QTimer();
    int i = 2000;
    //connect a signal to slot for create
    connect(timer , SIGNAL(timeout()),this, SLOT(Create()));
    timer->start(i);
    show();
}
void Game::Create(){
    //choose one of the shapes that inherits from object randomly and show it
    int rnumber1=rand()%3;
    if(rnumber1==1){
        Rectangle* rec=new Rectangle();
        scene->addItem(rec);
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
