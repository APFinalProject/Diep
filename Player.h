#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QWidget>
#include <QList>
#include <QTimer>
#include <QObject>
#include "health.h"

class Player : public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent * event );
    Health * p_health;

public slots:
    void collide_player();
};

#endif // PLAYER_H
