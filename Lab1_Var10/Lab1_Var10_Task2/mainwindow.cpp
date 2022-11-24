#include "mainwindow.h"
#include <QDebug>
#include <QApplication>

MainWindow::MainWindow()
{
    InitializeWindowAndLayout();
    CreateTableWidget();
    CreateToolbar();
}

void MainWindow::CreateToolbar()
{
    m_toolBar = new QToolBar();
    m_toolBar->addAction("Clear", [this]() { m_table->clearContents(); });
    m_toolBar->addAction("Exit", []() { QApplication::quit(); });
    m_toolBar->actions()[0]->setIcon(QIcon(":/ActionsIcons/archeology.png"));
    m_toolBar->actions()[1]->setIcon(QIcon(":/ActionsIcons/reject.png"));
    m_layout->insertWidget(0, m_toolBar);
}

void MainWindow::InitializeWindowAndLayout()
{
    m_window = new QWidget();
    m_window->resize(800, 600);
    m_window->setWindowTitle("QExcell");

    m_layout = new QVBoxLayout();
    m_window->setLayout(m_layout);
}

void MainWindow::CreateTableWidget()
{
    try {
        m_table = new QTableWidget();
        m_table->setColumnCount(5);
        m_table->setRowCount(10);

        QStringList horzHeaders;
        horzHeaders << "A" << "B" << "C" << "D" << "E" << "F";
        m_table->setHorizontalHeaderLabels(horzHeaders);

        m_layout->addWidget(m_table);
    }
    catch (const std::exception& ex) {
        qDebug() << "Create layout first!";
    }
}

void MainWindow::Show() { m_window->show(); }
