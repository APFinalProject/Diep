
#include <QApplication>
#include <QGraphicsScene>

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QGraphicsScene * scene = new QGraphicsScene();

    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();

    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);


    return a.exec();
}
