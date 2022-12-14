#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionClear_triggered()
{
    ui->tableWidget->clearContents();
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}

