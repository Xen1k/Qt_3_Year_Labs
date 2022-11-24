#include "listwidgetcontroller.h"
#include "filemanager.h"

#include <QDebug>
#include <QListWidgetItem>

namespace ListWidgetController {
    void AddItemsToList(QListWidget *qListWidget, JsonObject *jsonObject)
    {
        for(auto key : jsonObject->keys())
            qListWidget->addItem(key);
    }
}
