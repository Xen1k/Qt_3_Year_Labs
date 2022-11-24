#include "cosmoObjectItem.h"
#include <QDebug>

CosmoObjectItem::CosmoObjectItem(const QVector<QVariant> &data, CosmoObjectItem *parent)
    : itemData(data), m_parentItem(parent)
{
    if(parent)
        parent->appendChild(this);
}

CosmoObjectItem::~CosmoObjectItem()
{
    qDeleteAll(m_childItems);
}

void CosmoObjectItem::appendChild(CosmoObjectItem *item)
{
    m_childItems.append(item);
}

CosmoObjectItem *CosmoObjectItem::child(int row)
{
    if (row < 0 || row >= m_childItems.size())
        return nullptr;
    return m_childItems.at(row);
}

int CosmoObjectItem::childCount() const
{
    return m_childItems.count();
}

int CosmoObjectItem::row() const
{
    if (m_parentItem)
        return m_parentItem->m_childItems.indexOf(const_cast<CosmoObjectItem*>(this));

    return 0;
}

int CosmoObjectItem::columnCount() const
{
    return itemData.count();
}

QVariant CosmoObjectItem::data(int column) const
{
    if (column < 0 || column >= itemData.size())
        return QVariant();
    return itemData.at(column);
}

CosmoObjectItem *CosmoObjectItem::parentItem()
{
    return m_parentItem;
}
