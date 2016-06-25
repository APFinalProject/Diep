#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health :public QGraphicsTextItem
{

private:
    int health;
public:

    Health(int i_health = 0 , QGraphicsItem * parent=0 );
    int get_health(){
        return health;
    }
    void decrease();
    void setHealth(int i_health);
};

#endif // HEALTH_H
