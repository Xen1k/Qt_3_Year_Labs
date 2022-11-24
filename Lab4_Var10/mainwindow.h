#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonDocument>
#include "treeView.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    MainWindow(QWidget *parent = nullptr);
    TreeView *treeView;
    void UpdateTree();

public:
    static MainWindow &GetInstance();
    ~MainWindow();
    Ui::MainWindow *ui;

private slots:
    void on_actionSave_to_binary_triggered();

    void on_actionGet_from_binary_triggered();

private:
    QJsonDocument m_JsonDoc;
    MainWindow(MainWindow const&);
    void operator=(MainWindow const&);
};
#endif // MAINWINDOW_H
