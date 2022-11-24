#include "cosmoObjectModel.h"

CosmoObjectModel::CosmoObjectModel(const QVector<QVariant> &data, QObject *parent)
    : QAbstractItemModel(parent)
{
    rootItem = new CosmoObjectItem(data);
}

CosmoObjectModel::~CosmoObjectModel()
{
    delete rootItem;
}

QModelIndex CosmoObjectModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    CosmoObjectItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<CosmoObjectItem*>(parent.internalPointer());

    CosmoObjectItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    return QModelIndex();
}

QModelIndex CosmoObjectModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    CosmoObjectItem *childItem = static_cast<CosmoObjectItem*>(index.internalPointer());
    CosmoObjectItem *parentItem = childItem->parentItem();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int CosmoObjectModel::rowCount(const QModelIndex &parent) const
{
    CosmoObjectItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<CosmoObjectItem*>(parent.internalPointer());

    return parentItem->childCount();
}

int CosmoObjectModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<CosmoObjectItem*>(parent.internalPointer())->columnCount();
    return rootItem->columnCount();
}


QVariant CosmoObjectModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    CosmoObjectItem *item = static_cast<CosmoObjectItem*>(index.internalPointer());

    return item->data(dataColumn);
}

Qt::ItemFlags CosmoObjectModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index);
}

QVariant CosmoObjectModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}
