#include "score.h"
#include <QFont>
Score::Score(QGraphicsItem * parent):QGraphicsTextItem(parent)
{
    //initialize score to the zero.
    score=0;

    //draw the text
    setPlainText(QString("score:"+QString::number(score)));
    setDefaultTextColor(Qt::yellow);
    setFont(QFont("times",16));
}

void Score::increase(){
    score ++;
    setPlainText(QString("Score : ")+ QString::number(score));
}
