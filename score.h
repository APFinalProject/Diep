#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
#include <QGraphicsItem>

class Score : public QGraphicsTextItem
{
private:
    int score;
public:
    Score(const Score&);
    Score(QGraphicsItem * parent=0);
    int get_score(){
        return score;
    }
    void increase();
};

#endif // SCORE_H
