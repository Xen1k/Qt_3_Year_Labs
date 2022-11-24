#ifndef EDITABLELISTEDOBJECT_H
#define EDITABLELISTEDOBJECT_H

#include <QPushButton>
#include <functional>
#include <QListWidget>
#include <QGraphicsItem>

// Represents button in list view for editing and removing graphics object
class EditableListedObject
{
protected:
    QPushButton *actionButton;
    QPushButton *removeButton;
    QString selectedButtonStyle = "background-color: rgba(46, 204, 113, 0.4);";
    QString defaultButtonStyle = "background-color: rgba(255, 255, 255, 1.0);";
    void HightlightObjectsButton();
public:
    EditableListedObject(QString buttonText, std::function<void()> onClick, QGraphicsItem *graphicsItem);
    static EditableListedObject *lastSelectedObject;
};

#endif // EDITABLELISTEDOBJECT_H
