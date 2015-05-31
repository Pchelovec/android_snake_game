#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include "graf_viev_modicicate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_paint_PB_clicked()
{
    ui->graphicsView->setVisible(true);
        graf_viev_modicicate *g=new graf_viev_modicicate;
        g->set_size(ui->graphicsView->height(),ui->graphicsView->width());
        ui->graphicsView->setScene(g->paint());
}

