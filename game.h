#ifndef GAME_H
#define GAME_H
#include<QGraphicsScene>
#include<qgraphicsview>
#include"rectangle.h"
#include"square.h"
#include"triangle.h"
#include <QObject>
#include<QTimer>
#include"health.h"
#include"score.h"
class Game:public QGraphicsView
{
 Q_OBJECT
public:
    Game(QWidget * parent = 0);
    QGraphicsScene * scene;
public slots:
    void Create();
};

#endif // GAME_H
