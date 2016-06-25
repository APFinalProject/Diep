#include "button.h"


Button::Button(QString s)
{
    button = QPixmap(s);
    setPixmap(button);

}
void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}
