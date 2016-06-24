#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include "object.h"
#include "triangle.h"
#include "square.h"
#include "player.h"
#include "score.h"
#include "health.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);
    QGraphicsScene *scene;
    Player *player;
    Score * score;
    Health * health;

signals:

public slots:
    void create();

};

#endif // GAME_H
