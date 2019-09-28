#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mygraphicsscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionSelect_triggered();

    void on_actionDraw_triggered();

private:
    Ui::MainWindow *ui;
    MyGraphicsScene *myscene;
};

#endif // MAINWINDOW_H
