#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mygraphicsscene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(new MyGraphicsScene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
