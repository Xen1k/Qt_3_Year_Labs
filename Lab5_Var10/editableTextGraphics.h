#ifndef EDITABLETEXTGRAPHICS_H
#define EDITABLETEXTGRAPHICS_H

#include <QGraphicsItem>
#include <QPainter>
#include "editableListedObject.h"

class EditableTextGraphics : public QGraphicsItem, public EditableListedObject
{
private:
    QString m_Text;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void UpdateText();
public:
    EditableTextGraphics(QString text);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
};

#endif // EDITABLETEXTGRAPHICS_H
