#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QTimer>

#include <QThread>

class Mythread : public QThread
{
    Q_OBJECT
public:
    explicit Mythread(QObject *parent = 0);
    QTimer *timer1;
    void run(int time);
signals:
    void signal1();
    
public slots:
    void slot1();
    
};

#endif // MYTHREAD_H
