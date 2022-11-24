#ifndef ADDTODATABASEFORM_H
#define ADDTODATABASEFORM_H

#include <QDialog>
#include "json.h"

using QtJson::JsonObject;

namespace Ui {
class AddToDatabaseForm;
}

class AddToDatabaseForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddToDatabaseForm(QWidget *parent = nullptr);
    ~AddToDatabaseForm();
    JsonObject jsonObject;

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddToDatabaseForm *ui;
    bool IsFilled();
};

#endif // ADDTODATABASEFORM_H
