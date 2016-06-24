#ifndef BULLET_H
#define BULLET_H
#include <QTimer>
#include<Qlist>
#include<typeinfo>
#include <QObject>
#include <QGraphicsPixmapItem>
class Bullet : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Bullet(QObject *parent = 0);

signals:

public slots:
    void move();

};

#endif // BULLET_H
