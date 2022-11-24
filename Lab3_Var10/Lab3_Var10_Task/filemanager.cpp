#include "filemanager.h"
#include <QDir>
#include <QTextStream>


namespace FileManager {

    QString ReadFile(const QString &filename) {
        QFile f(QDir::currentPath() + "/" + filename);
        if (!f.open(QFile::ReadOnly | QFile::Text)) {
            return QString();
        } else {
            QTextStream in(&f);
            return in.readAll();
        }
    }

    void WriteFile(const QString &filename, JsonObject *jsonObject)
    {
        QFile f(QDir::currentPath() + "/" + filename);
        if (f.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
            QTextStream stream(&f);
            stream << QtJson::serialize(*jsonObject) << endl;
        }
    }
}
