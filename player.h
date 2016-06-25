#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QWidget>
#include <QObject>
#include "health.h"
#include <QVector>
#include "bullet.h"

class Player : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = 0);
    void keyPressEvent(QKeyEvent * event );
    QVector<Bullet*> v_bullet;


signals:

public slots:
     void collide_player();
     void delete_bullets();

};

#endif // PLAYER_H
