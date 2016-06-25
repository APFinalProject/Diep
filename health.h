#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health :public QGraphicsTextItem
{

public:
    int health;
public:

    Health(QGraphicsItem * parent=0 , int i_health = 5);
    int get_health(){
        return health;
    }
    void decrease();
    void setHealth(int i_health);

};

#endif // HEALTH_H
