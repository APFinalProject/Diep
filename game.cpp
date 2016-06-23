#include "game.h"
#include"stdlib.h"

Game::Game(QWidget * parent):QGraphicsView(parent)
{
    scene=new QGraphicsScene;
    //->setFlag(QGraphicsItem::ItemIsFocusable);
    //player->setFocus();
    setScene(scene);
    //scene->addItem(player);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    QTimer * timer = new QTimer();
    int i = 2000;
    connect(timer , SIGNAL(timeout()),this, SLOT(Create()));
    timer->start(i);
    show();
}
void Game::Create(){
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
