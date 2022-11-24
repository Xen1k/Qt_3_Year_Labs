#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QToolBar>
#include <QAction>

class MainWindow
{
public:
    MainWindow();
    void Show();
private:
    QTableWidget *m_table;
    QVBoxLayout *m_layout;
    QWidget *m_window;
    QToolBar *m_toolBar;

    void InitializeWindowAndLayout();
    void CreateTableWidget();
    void CreateToolbar();

};

#endif // MAINWINDOW_H
