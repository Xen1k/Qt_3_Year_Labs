#include "editableImageGraphics.h"
#include <QGraphicsSceneMouseEvent>

EditableImageGraphics::EditableImageGraphics() :
    QGraphicsPixmapItem(QPixmap::fromImage(QImage(":/zevs")).scaledToWidth(100)),
    EditableListedObject::EditableListedObject(
        "Image",
        [=]() { ChangeImage(); },
        this
    )
{
    this->setFlag(QGraphicsItem::ItemIsSelectable, true);
    this->setFlag(QGraphicsItem::ItemIsMovable, true);
}

void EditableImageGraphics::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() & Qt::RightButton)
        HightlightObjectsButton();
}


void EditableImageGraphics::ChangeImage()
{
    m_CurrentImageIndex = m_CurrentImageIndex >= 2 ? 0 : m_CurrentImageIndex + 1;

    setPixmap(QPixmap::fromImage(QImage(m_Images[m_CurrentImageIndex])).scaledToWidth(100));
}
