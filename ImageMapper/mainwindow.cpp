#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mygraphicsscene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myscene = new MyGraphicsScene;
    ui->graphicsView->setScene(myscene);
    ui->graphicsView->setSceneRect(ui->graphicsView->rect());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSelect_triggered()
{
    myscene->setMode(EditMode::Select);
}

void MainWindow::on_actionDraw_triggered()
{
    myscene->setMode(EditMode::Draw);
}
