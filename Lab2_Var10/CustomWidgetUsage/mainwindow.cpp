#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <build-XenonForm-Desktop_Qt_5_12_12_MSVC2015_64bit-Debug/../../XenonForm/xenonform.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    XenonForm *xenonForm = new XenonForm();
    xenonForm->SetLabelString("Form label");
//    xenonForm->SetButtonAction([]() { QApplication::quit(); });

    this->layout()->addWidget(xenonForm);
}

MainWindow::~MainWindow()
{
    delete ui;
}

