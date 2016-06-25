#ifndef BUTTON_H
#define BUTTON_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QString>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include "game.h"
//extern Game * game;
class Button : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Button(QString);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
signals:
     void clicked();
private:
     QPixmap button;
};

#endif // BUTTON_H
