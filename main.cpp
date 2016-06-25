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
   }
