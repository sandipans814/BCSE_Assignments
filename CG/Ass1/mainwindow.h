#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void Mouse_Pressed();
    void showMousePosition(QPoint &pos);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_showGrid_clicked();

    void on_showAxes_clicked();

    int changeX(int x);

    int changeY(int y);

    void on_setPoint1_clicked();

    void on_unsetPoint1_clicked();

    void on_setPoint2_clicked();

    void on_unsetPoint2_clicked();

    void on_gridSize_valueChanged(int arg1);

    void on_drawLine_clicked();

private:
    Ui::MainWindow *ui;
    void point(int x, int y, int r = 255, int g = 0, int b = 0);
    QPoint p1; QPoint p2;
    void DDA();
    void Bresenham();
};
#endif // MAINWINDOW_H
