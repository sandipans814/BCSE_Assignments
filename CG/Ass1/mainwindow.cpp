#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QDebug>
#include <QString>

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->myScreen, SIGNAL(Mouse_Pos()),this,SLOT(Mouse_Pressed()));
    connect(ui->myScreen,SIGNAL(sendMousePosition(QPoint&)),this,SLOT(showMousePosition(QPoint&)));
    ui->showGrid->click();
    p1.setX(0); p1.setY(0);
    p2.setX(0); p2.setY(0);
}

QImage img = QImage(700, 700, QImage::Format_RGB32);

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::point(int x,int y, int r, int g, int b) // int r,int g,int b
{
    int k = ui->gridSize->value();//GridSize
    if(k>1)
    {
        int startX=x/k*k;
        int startY=y/k*k;

        //Drawing the pixels
        for(int i=startX+1;i<(startX+k);i++)
            for(int j=startY+1;j<(startY+k);j++)
                img.setPixel(i,j,qRgb(r, g, b));
    }
    else
        img.setPixel(x, y, qRgb(r, g, b));
    ui->myScreen->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::Mouse_Pressed()
{
    ui->mousePressed->setText(" X : "+QString::number(changeX(ui->myScreen->x))+", Y : "+QString::number(changeY(ui->myScreen->y)));
    point(ui->myScreen->x,ui->myScreen->y);
//    ui->x_axis->move(0,ui->myScreen->y);
//    ui->y_axis->move(ui->myScreen->x,0);
}

int MainWindow::changeX(int x)
{
//    qDebug() << x;
      int k = ui->gridSize->value();
      x = x / k;
      int mid = img.width() / 2 / k;
      x = x - mid;
      return x;

}

int MainWindow::changeY(int y)
{
//    qDebug() << y;
    int k = ui->gridSize->value();
    y = y / k;
    int mid = img.width() / 2 / k;
    y = mid - y;
    return y;
}

void MainWindow::showMousePosition(QPoint &pos)
{
//    qDebug() << pos.x() << pos.y();
    ui->mouseMovement->setText(" X : "+QString::number(changeX(pos.x()))+", Y : "+QString::number(changeY(pos.y())));
}

void MainWindow::on_showGrid_clicked()
{
    int s = ui->gridSize->value();
    if (s <= 0) {
        qDebug() << "Grid Size 0 is not supported!";
        return;
    }
    for (int i = 1; i < 700; i++) {
        for (int j = 1; j < 700; ++j) {
            if(i % s == 0 || j % s == 0)
                img.setPixel(i, j, qRgb(255, 255, 255));
            else
                img.setPixel(i, j, qRgb(0, 0, 0));
        }
    }
    ui->myScreen->setPixmap(QPixmap::fromImage(img));
    ui->showAxes->setCheckState(Qt::Unchecked);
}

void MainWindow::on_showAxes_clicked()
{
    int size = ui->gridSize->value();
    int start = (img.height() / (2 * size));
    int end = start + 1;
    if(ui->showAxes->isChecked())
    {
            for(int i = 0; i < img.width(); ++i){
                for (int j = start * size; j <= end * size; ++j) {
                    if(i % size == 0 || j % size == 0){
                        img.setPixel(i, j, qRgb(255, 255, 255));
                        img.setPixel(j, i, qRgb(255, 255, 255));
                    }
                    else {
                        img.setPixel(i, j, qRgb(176,136,249));
                        img.setPixel(j, i, qRgb(176,136,249));
                    }
                }
            }

            ui->myScreen->setPixmap(QPixmap::fromImage(img));
//            qDebug() << start << end << "\n";
    }
    else{
            for(int i = 0; i < img.width(); ++i){
                for (int j = start * size; j <= end * size; ++j) {
                    if(i % size == 0 || j % size == 0){
                        img.setPixel(i, j, qRgb(255, 255, 255));
                        img.setPixel(j, i, qRgb(255, 255, 255));
                    }
                    else {
                        img.setPixel(i, j, qRgb(0, 0, 0));
                        img.setPixel(j, i, qRgb(0, 0, 0));
                    }
                }
            }

            ui->myScreen->setPixmap(QPixmap::fromImage(img));
    }
}

void MainWindow::on_setPoint1_clicked()
{
    if(ui->myScreen->x <= 0 || ui->myScreen->y <= 0){
        qDebug() << "No pixel was clicked, cannot set Point 1!";
        return;
    }
    if(changeX(ui->myScreen->x) == changeX(p2.x()) && changeY(ui->myScreen->y) == changeY(p2.y())) {
        qDebug() << "Point 1 cannot be the same as Point 2 for Line Drawing!";
        return;
    }
    p1.setX(ui->myScreen->x);
    p1.setY(ui->myScreen->y);
    point(p1.x(), p1.y(), 255, 0, 0);
    qDebug() << p1.x() << p1.y() << "\n";
}

void MainWindow::on_unsetPoint1_clicked()
{
    if(p1.x() <= 0 || p1.y() <= 0){
        qDebug() << "Cannot unset Point 1!";
        return;
    }
    point(p1.x(), p1.y(), 0, 0, 0);
    p1.setX(0);
    p1.setY(0);
    qDebug() << p1.x() << p1.y() << "\n";
}

void MainWindow::on_setPoint2_clicked()
{
    if(ui->myScreen->x <= 0 || ui->myScreen->y <= 0){
        qDebug() << "No pixel was clicked, cannot set Point 2!";
        return;
    }
    if(changeX(ui->myScreen->x) == changeX(p1.x()) && changeY(ui->myScreen->y) == changeY(p1.y())) {
        qDebug() << "Point 2 cannot be the same as Point 1 for Line Drawing!";
        return;
    }
    p2.setX(ui->myScreen->x);
    p2.setY(ui->myScreen->y);
    point(p2.x(), p2.y(), 255, 0, 0);
    qDebug() << p2.x() << p2.y() << "\n";
}



void MainWindow::on_unsetPoint2_clicked()
{
    if(p2.x() <= 0 || p2.y() <= 0){
        qDebug() << "Cannot unset Point 2!";
        return;
    }
    point(p2.x(), p2.y(), 0, 0, 0);
    p2.setX(0);
    p2.setY(0);
    qDebug() << p2.x() << p2.y() << "\n";
}

void MainWindow::on_gridSize_valueChanged(int arg1)
{
    p1.setX(0); p1.setY(0);
    p2.setX(0), p2.setY(0);
    ui->myScreen->x = 0;
    ui->myScreen->y = 0;
    ui->mouseMovement->setText("");
    ui->mousePressed->setText("");
    ui->showGrid->click();
    ui->showAxes->setCheckState(Qt::Unchecked);
}

void MainWindow::DDA() {
    int size = ui->gridSize->value();
    int dx = 0, dy = 0;

    int x1 = changeX(p1.x());
    int y1 = changeY(p1.y());

    int x2 = changeX(p2.x());
    int y2 = changeY(p2.y());

    dx = x2 - x1;
    dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    qDebug() << "x1 and y1: " << x1 << y1;
    qDebug() << "x2 and y2: " << x2 << y2;

    float XInc = dx / (float)steps;
    float YInc = dy / (float)steps;

    qDebug() << "x_inc and y_inc: " << XInc << YInc;

    float x = x1, y = y1;

//    x = ((img.height() / 2 / size) + x1) * size;
//    y = ((img.height() / 2 / size) - y1) * size;

    qDebug() << "x and y: " << x << y;

    for(int i = 0; i < steps; i++) {
//        point((int)x, (int)y, 255, 0, 0);
        x = x + XInc;
        y = y + YInc;
        qDebug() << i + 1 <<" x and y: " << x << y;
        int x_plot = ((img.width() / 2 / size) + round(x)) * size;
        int y_plot = ((img.height() / 2 / size) - round(y)) * size;
        point(x_plot, y_plot, 255, 0, 0);
    }

//    qDebug() << x1 << y1 << "," << x2 << y2;
}

void MainWindow::Bresenham() {
    int size = ui->gridSize->value();

    int x1 = p1.x();
    int y1 = p1.y();

    int x2 = p2.x();
    int y2 = p2.y();

    int dx = (x2 - x1);
    int dy = (y2 - y1);

    x1 = (x1 / size) * size + size / 2;
    y1 = (y1 / size) * size + size / 2;

    x2 = (x2 / size) * size + size / 2;
    y2 = (y2 / size) * size + size / 2;

    int x_inc = (dx > 0) ? size : - size;
    int y_inc = (dy > 0) ? size : - size;

    dx = abs(dx);
    dy = abs(dy);

    if(dx > dy) {
        int p = 2 * dy - dx;
        int y = y1;

        for(int x = x1; x != x2; x += x_inc)
        {
            point(x, y, 255, 0, 0);
            if(p >= 0)
            {
                y += y_inc;
                p -= 2 * dx;
            }
            p += 2 * dy;
        }
    } else {
        int p = 2 * dx - dy;
        int x = x1;

        for(int y = y1; y != y2; y += y_inc)
        {
            point(x, y, 255, 0, 0);
            if(p >= 0)
            {
                x += x_inc;
                p -= 2 * dy;
            }
            p += 2 * dx;
        }
    }
}

void MainWindow::on_drawLine_clicked()
{
    if(p1.y() && p1.y() && p2.x() && p2.y()){
        if(ui->selectLineDrawAlgo->currentIndex() == 0)
            DDA();
        else {
            Bresenham();
        }
    } else {
        qDebug() << "Both points need to be set for Line Drawing";
        return;
    }
}
