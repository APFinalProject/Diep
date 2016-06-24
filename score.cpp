#include "score.h"
#include <QFont>
#include <game.h>

extern Game * game;
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
}
Score::Score(const Score & sc){
this->score=sc.score;
}
