#ifndef GAME_H
#define GAME_H
#include<QGraphicsScene>
#include<qgraphicsview>
#include <QGraphicsItem>
#include <QObject>
#include<QTimer>
#include <QWidget>
#include "button.h"
#include "triangle.h"
#include "square.h"
#include "Player.h"
#include "score.h"
#include "health.h"

class Game : public QGraphicsView
{
 Q_OBJECT
public:
    Game(QWidget * parent =0);
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
    Button * quitt;
    Button * restartt;
    Button * startt;
    void menu();
    void gameover();
public slots:
    void create();
    void start();
    void newgame();

};

#endif // GAME_H
