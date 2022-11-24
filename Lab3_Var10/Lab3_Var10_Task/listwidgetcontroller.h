#ifndef LISTWIDGETCONTROLLER_H
#define LISTWIDGETCONTROLLER_H

#include <QListWidget>
#include <functional>
#include "json.h"

using QtJson::JsonObject;

namespace ListWidgetController {
    void AddItemsToList(QListWidget *qListWidget, JsonObject *jsonObject);
    void SetItemsAction(QListWidget *qListWidget, std::function<void ()> action);
}


#endif // LISTWIDGETCONTROLLER_H
