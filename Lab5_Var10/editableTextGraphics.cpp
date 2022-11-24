#include "editableTextGraphics.h"
#include <QGuiApplication>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsSceneMouseEvent>

EditableTextGraphics::EditableTextGraphics(QString text) :
    EditableListedObject::EditableListedObject(
        text + " (Edit text)",
        [=]() { UpdateText(); },
        this
    ),
    m_Text(text)
{
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->setFlag(QGraphicsItem::ItemIsMovable, true);
}

void EditableTextGraphics::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() & Qt::RightButton)
        HightlightObjectsButton();
}


void EditableTextGraphics::UpdateText()
{
    m_Text = MainWindow::GetInstance().ui->textInput->text();
    this->actionButton->setText(m_Text + " (Edit text)");
}


void EditableTextGraphics::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawText(0, 0, m_Text);
}

QRectF EditableTextGraphics::boundingRect() const
{
    return QRectF(-50, -50, 100, 100);
}
