#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cosmoObjectModel.h"
#include <QPushButton>
#include <vector>
#include <QFile>
#include <QDebug>
#include <QJsonObject>

QJsonDocument LoadHierarchyFromJSON()
{
    QString val;
    QFile file;
    file.setFileName(":cosmoObjects.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    return QJsonDocument::fromJson(val.toUtf8());
}

void SaveJsonToBinary(QJsonDocument &doc)
{
    QString filename = "hierarchy.bin";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite | QIODevice::Truncate)) {
        QDataStream stream(&file);
        stream << doc.toBinaryData();
    }
}

QJsonDocument ReadFromBinaryToJson()
{
    QFile file("./hierarchy.bin");
    file.open(QIODevice::ReadOnly);

    QByteArray ba;
    QDataStream in(&file);
    in >> ba;
    file.close();
    return QJsonDocument::fromBinaryData(ba);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->_nameLabel->setWordWrap(true);
    ui->description->setWordWrap(true);

    treeView = new TreeView();
    ui->verticalLayout_2->addWidget(treeView);

    m_JsonDoc = LoadHierarchyFromJSON();
    CosmoObjectModel *model = new CosmoObjectModel({ "Космические объекты (Два клика для информации)" });

    UpdateTree();
}

void MainWindow::UpdateTree()
{
    CosmoObjectModel *model = new CosmoObjectModel({ "Космические объекты (Два клика для информации)" });

    auto parentItem = model->rootItem;
    for (auto el : m_JsonDoc.object())
        parentItem = new CosmoObjectItem({ el.toObject()["name"].toString(),
                                           el.toObject()["description"].toString(),
                                           el.toObject()["image"].toString() },
                                         parentItem);

    treeView->setModel(model);
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

void MainWindow::on_actionSave_to_binary_triggered()
{
    SaveJsonToBinary(m_JsonDoc);
}


void MainWindow::on_actionGet_from_binary_triggered()
{
    m_JsonDoc = ReadFromBinaryToJson();
    UpdateTree();
}

