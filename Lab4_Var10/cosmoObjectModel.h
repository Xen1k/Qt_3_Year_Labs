#ifndef COSMOOBJECTMODEL_H
#define COSMOOBJECTMODEL_H

#include <QAbstractItemModel>
#include <vector>
#include "cosmoObjectItem.h"

class CosmoObjectModel : public QAbstractItemModel
{
public:
    explicit CosmoObjectModel(const QVector<QVariant> &data, QObject *parent = nullptr);
    ~CosmoObjectModel();

    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    CosmoObjectItem *rootItem;
    int dataColumn = 0;

};

#endif // COSMOOBJECTMODEL_H
