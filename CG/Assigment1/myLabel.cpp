#include "myLabel.h"

myLabel::myLabel(QWidget *parent):QLabel(parent)
{
    this->setMouseTracking(true);
}

void myLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QPoint mouse_pos = ev->pos();
    if(mouse_pos.x() <= this->size().width() && mouse_pos.y() <= this->size().height()){
        if(mouse_pos.x() > 0 && mouse_pos.y() > 0){
            emit sendMousePosition(mouse_pos);
        }
    }
}

void myLabel::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton){
        this->x = ev->x();
        this->y = ev->y();
        emit Mouse_Pos();
    }
}
