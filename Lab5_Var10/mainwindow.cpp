#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "editableTextGraphics.h"
#include "editableRectGraphics.h"
#include "editableImageGraphics.h"
#include <QPushButton>
#include <QDebug>
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow& MainWindow::GetInstance()
{
    static MainWindow instance;
    return instance;
};

void MainWindow::on_addTextButton_clicked()
{
    scene->addItem(new EditableTextGraphics(ui->textInput->text()));
    ui->textInput->setText("");
}


void MainWindow::on_addRectButton_clicked()
{
    scene->addItem(new EditableRectGraphics());
}


void MainWindow::on_addImageButton_clicked()
{
    scene->addItem(new EditableImageGraphics());
//    QPixmap pixmap = QPixmap::fromImage(QImage(":/zevs")).scaledToWidth(100);
//    auto scenePixmap = scene->addPixmap(pixmap);
//    scenePixmap->setFlag(QGraphicsItem::ItemIsSelectable, true);
//    scenePixmap->setFlag(QGraphicsItem::ItemIsMovable, true);
}

