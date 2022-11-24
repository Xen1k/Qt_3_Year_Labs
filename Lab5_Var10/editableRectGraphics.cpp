#include "editableRectGraphics.h"
#include <QGraphicsSceneMouseEvent>


EditableRectGraphics::EditableRectGraphics() :
    QGraphicsRectItem(0, 0, 100, 100),
    EditableListedObject::EditableListedObject(
        "Rect",
        [=]() { ChangeColor(); },
        this
    )
{
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->setFlag(QGraphicsItem::ItemIsMovable, true);
    ChangeColor();
}

void EditableRectGraphics::ChangeColor()
{
    setBrush(QColor(rand() % 255, rand() % 255, rand() % 255));
}

void EditableRectGraphics::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() & Qt::RightButton)
        HightlightObjectsButton();
}
