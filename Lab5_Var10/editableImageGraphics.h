#ifndef EDITABLEIMAGEGRAPHICS_H
#define EDITABLEIMAGEGRAPHICS_H

#include "editableListedObject.h"
#include <QGraphicsPixmapItem>

class EditableImageGraphics : public QGraphicsPixmapItem, public EditableListedObject
{
private:
    unsigned short m_CurrentImageIndex = 0;
    QString m_Images[3] = { ":/zevs", ":/poseidon", ":/aid" };
    void ChangeImage();
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
public:
    EditableImageGraphics();
};


#endif // EDITABLEIMAGEGRAPHICS_H
