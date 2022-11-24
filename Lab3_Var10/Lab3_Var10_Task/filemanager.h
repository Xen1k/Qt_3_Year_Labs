#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "json.h"

using QtJson::JsonObject;

namespace FileManager {
    QString ReadFile(const QString &filename);
    void WriteFile(const QString &filename, JsonObject *jsonObject);
}


#endif // FILEMANAGER_H
