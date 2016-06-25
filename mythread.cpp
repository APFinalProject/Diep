#include "mythread.h"

Mythread::Mythread(QObject *parent) :
    QThread(parent)
{

}

void Mythread::run(int timer)
{
    timer1 = new QTimer();
    connect(timer1,SIGNAL(timeout()),this,SLOT(slot1()));
    timer1->start(timer);
    timer1->moveToThread(this);
}


void Mythread::slot1()
{
    emit signal1();
}
