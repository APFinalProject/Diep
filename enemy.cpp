#include "enemy.h"
#include<stdlib.h>
Enemy::Enemy()
{
int rnumber1=rand()%3;
if(rnumber1==1){
    Rectangle();
}
else if(rnumber1==2){
    Square();
}
else{
    Triangle();
}
}
void Enemy::Create(){
    Enemy *en = new Enemy();
    scene()->addItem(en);
}
