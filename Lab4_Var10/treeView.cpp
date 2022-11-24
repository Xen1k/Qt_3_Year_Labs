#include "treeView.h"
#include "cosmoObjectItem.h"
#include "cosmoObjectModel.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>

TreeView::TreeView(QWidget *parent) : QTreeView(parent) {}

void TreeView::mouseDoubleClickEvent(QMouseEvent * event)
{
    QModelIndexList indexes = selectionModel()->selectedIndexes();
    if (indexes.size() > 0) {
        QModelIndex selectedIndex = indexes.at(0);
        static_cast<CosmoObjectModel*>(this->model())->dataColumn = 0;
        MainWindow::GetInstance().ui->_nameLabel->setText(this->model()->data(selectedIndex).toString());
        static_cast<CosmoObjectModel*>(this->model())->dataColumn = 1;
        MainWindow::GetInstance().ui->description->setText(this->model()->data(selectedIndex).toString());

        static_cast<CosmoObjectModel*>(this->model())->dataColumn = 2;
        QLabel *labelImage = MainWindow::GetInstance().ui->image;
        QPixmap pixmap(":/images/" + this->model()->data(selectedIndex).toString());
        labelImage->setPixmap(pixmap.scaledToWidth(200));
        labelImage->show();

        static_cast<CosmoObjectModel*>(this->model())->dataColumn = 0;
    }

}


