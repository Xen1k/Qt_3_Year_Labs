#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "editableListedObject.h"
#include <QDebug>
#include <QListWidgetItem>
#include <QGraphicsView>

EditableListedObject* EditableListedObject::lastSelectedObject;

EditableListedObject::EditableListedObject(QString buttonText, std::function<void()> onClick, QGraphicsItem *graphicsItem)
{
    QListWidget *listWidget = MainWindow::GetInstance().ui->itemsList;
    QGraphicsView *graphicsView = MainWindow::GetInstance().ui->graphicsView;

    // Add action button (ex: change text)
    actionButton = new QPushButton();
    actionButton->setText(buttonText);
    actionButton->setStyleSheet(defaultButtonStyle);
    QObject::connect(actionButton, &QPushButton::clicked, [=]() {
        onClick();
        graphicsView->viewport()->repaint();
    });
    QListWidgetItem* actionButtonItem = new QListWidgetItem(listWidget);
    listWidget->setItemWidget(actionButtonItem, actionButton);

    // Add remove button
    removeButton = new QPushButton();
    removeButton->setText("-");
    removeButton->setStyleSheet(defaultButtonStyle);
    QListWidgetItem* removeButtonItem = new QListWidgetItem(listWidget);
    QObject::connect(removeButton, &QPushButton::clicked, [=]() {
        listWidget->removeItemWidget(actionButtonItem);
        listWidget->removeItemWidget(removeButtonItem);
        graphicsView->scene()->removeItem(graphicsItem);
        delete actionButtonItem;
        delete removeButtonItem;
        delete actionButton;
        delete removeButton;
        if(lastSelectedObject == this) lastSelectedObject = nullptr;
    });
    listWidget->setItemWidget(removeButtonItem, removeButton);
}

void EditableListedObject::HightlightObjectsButton()
{
    actionButton->setStyleSheet(selectedButtonStyle);
    removeButton->setStyleSheet(selectedButtonStyle);
    if(lastSelectedObject)
    {
        lastSelectedObject->removeButton->setStyleSheet(defaultButtonStyle);
        lastSelectedObject->actionButton->setStyleSheet(defaultButtonStyle);
    }
   lastSelectedObject = this;
}
