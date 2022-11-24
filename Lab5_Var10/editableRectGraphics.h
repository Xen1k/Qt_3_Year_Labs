#ifndef EDITABLERECTGRAPHICS_H
#define EDITABLERECTGRAPHICS_H

#include "editableListedObject.h"
#include <QGraphicsRectItem>

class EditableRectGraphics : public QGraphicsRectItem, public EditableListedObject
{
private:
    void ChangeColor();
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
public:
    EditableRectGraphics();

};


#endif // EDITABLERECTGRAPHICS_H
