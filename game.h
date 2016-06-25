#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QVector>
#include <QObject>
#include "object.h"
#include "triangle.h"
#include "square.h"
#include "player.h"
#include "score.h"
#include "health.h"
#include <QTimer>
class Game :public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);
    QGraphicsScene *scene;
    Player *player;
    Score * score;
    Health * health;
    QVector<Object *> objects;

public slots:
    void create();
  };
#endif // GAME_H
