#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>
class Health :public QGraphicsTextItem
{

private:
    int health;
public:

    Health(QGraphicsItem * parent=0);
    int get_health(){
        return health;
    }
    void decrease();
};

#endif // HEALTH_H

