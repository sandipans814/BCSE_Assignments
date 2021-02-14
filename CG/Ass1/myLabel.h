#ifndef MYLABEL_H
#define MYLABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QEvent>

class myLabel : public QLabel
{
    Q_OBJECT

public:
    myLabel(QWidget *parent = 0);
    int x,y;

protected:
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
signals:
    void sendMousePosition(QPoint&);
    void Mouse_Pos();
};

#endif // MYLABEL_H
