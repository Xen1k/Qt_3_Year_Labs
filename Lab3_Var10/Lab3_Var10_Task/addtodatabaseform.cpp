#include "addtodatabaseform.h"
#include "ui_addtodatabaseform.h"

#include <QDebug>
#include "filemanager.h"

AddToDatabaseForm::AddToDatabaseForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddToDatabaseForm)
{
    ui->setupUi(this);
}

AddToDatabaseForm::~AddToDatabaseForm()
{
    delete ui;
}

bool AddToDatabaseForm::IsFilled()
{
    return !(ui->specialityInput->text().isEmpty() ||
            ui->groupInput->text().isEmpty() ||
            ui->surnameInput->text().isEmpty() ||
            ui->bookNumberInput->text().isEmpty());
}

void AddToDatabaseForm::on_pushButton_clicked()
{
    if(IsFilled())
    {
        JsonObject specialityData = jsonObject[ui->specialityInput->text()].toMap();
        JsonObject groupData = specialityData[ui->groupInput->text()].toMap();
        JsonObject studentData = groupData[ui->surnameInput->text()].toMap();

        studentData["record_book_number"] = ui->bookNumberInput->text();
        groupData[ui->surnameInput->text()] = studentData;
        specialityData[ui->groupInput->text()] = groupData;
        jsonObject[ui->specialityInput->text()] = specialityData;

        FileManager::WriteFile("database.json", &jsonObject);
        this->close();
    }
}

