#ifndef COSMOOBJECTITEM_H
#define COSMOOBJECTITEM_H

#include "qvariant.h"
#include "qvector.h"
#include <QPushButton>

class CosmoObjectItem
{
public:
    explicit CosmoObjectItem(const QVector<QVariant> &data, CosmoObjectItem *parentItem = nullptr);
    ~CosmoObjectItem();

    void appendChild(CosmoObjectItem *child);

    CosmoObjectItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    CosmoObjectItem *parentItem();

    QVector<QVariant> itemData;
private:
    QVector<CosmoObjectItem*> m_childItems;
    CosmoObjectItem *m_parentItem;
};

#endif // COSMOOBJECTITEM_H
