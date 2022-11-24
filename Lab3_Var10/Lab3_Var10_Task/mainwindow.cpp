#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filemanager.h"
#include "listwidgetcontroller.h"
#include "addtodatabaseform.h"

#include <memory>
#include <QMessageBox>
#include <QDebug>

using std::unique_ptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Refresh();
}

void MainWindow::Refresh()
{
    QString jsonFile = FileManager::ReadFile("database.json");
    if (jsonFile.isEmpty()) {
        qFatal("Could not read JSON file!");
        return;
    }

    ui->specialitiesList->clear();
    ui->groupsList->clear();
    ui->studentsList->clear();

    jsonObject = QtJson::parse(jsonFile).toMap();
    ListWidgetController::AddItemsToList(ui->specialitiesList, &jsonObject);

    connect(ui->specialitiesList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ShowGroupsList(QListWidgetItem*)));
    connect(ui->groupsList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ShowStudentsList(QListWidgetItem*)));
    connect(ui->studentsList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ShowRecordBookNumber(QListWidgetItem*)));
}

void MainWindow::ShowGroupsList(QListWidgetItem* item)
{
    ui->groupsList->clear();
    ui->studentsList->clear();
    JsonObject groups = jsonObject[item->text()].toMap();
    ListWidgetController::AddItemsToList(ui->groupsList, &groups);
    lastSelectedSpeciality = item->text();
}

void MainWindow::ShowStudentsList(QListWidgetItem* item)
{
    ui->studentsList->clear();
    JsonObject students = jsonObject[lastSelectedSpeciality].toMap()[item->text()].toMap();
    ListWidgetController::AddItemsToList(ui->studentsList, &students);
    lastSelectedGroup = item->text();
}

void MainWindow::ShowRecordBookNumber(QListWidgetItem* item)
{
    QString recordBookNumber =
            jsonObject[lastSelectedSpeciality].toMap()
            [lastSelectedGroup].toMap()
            [item->text()].toMap()
            ["record_book_number"].toString();
    unique_ptr<QMessageBox> msgBox(new QMessageBox());
    msgBox->setText(recordBookNumber);
    msgBox->exec();

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionAdd_New_triggered()
{
    unique_ptr<AddToDatabaseForm> dataBaseFormWindow(new AddToDatabaseForm());
    dataBaseFormWindow->jsonObject = jsonObject;
    dataBaseFormWindow->exec();
    Refresh();
}

