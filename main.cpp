#include <QApplication>
#include<QGraphicsView>
#include<QGraphicsScene>
#include"object.h"
#include"triangle.h"
#include"rectangle.h"
#include"square.h
#include"game.h"
#include <QObject>
#include <QTimer>
Game *game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game=new Game;
    game->show();
    return a.exec();
}
