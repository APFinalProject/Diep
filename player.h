#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QWidget>

class Player : public QGraphicsPixmapItem
{
public:
     Player();
     void keyPressEvent(QKeyEvent * event );

signals:

public slots:

};

#endif // PLAYER_H
