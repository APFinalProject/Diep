
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "player.h"
#include "triangle.h"
#include "square.h"
#include "game.h"

Game * game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();
    return a.exec();
   /* QGraphicsScene * scene = new QGraphicsScene();

    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    Player *player = new Player();

    scene->addItem(player);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    Triangle *tri = new Triangle();
    scene->addItem(tri);
    Square *squ = new Square();
    scene->addItem(squ);


    view->show();

    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
*/


}
