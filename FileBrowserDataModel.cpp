#include "FileBrowserDataModel.h"


FileBrowserDataModel::FileBrowserDataModel(const QList<SomeData> &dt, QObject *parent) : QAbstractTableModel(parent)
{
    dataModel = dt;
}


void FileBrowserDataModel::setModel(const QList<SomeData> &dt)
{
    beginResetModel();
    dataModel = dt;
    endResetModel();
}

//определение количества строк в модели;

int FileBrowserDataModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return dataModel.count();
}

//определение количества столбцов в модели

int FileBrowserDataModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return PERCENT + 1;
}

//Возвращаем названия заголовков.

QVariant FileBrowserDataModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if (orientation == Qt::Vertical)
    {
        return section;
    }

    switch (section)
    {
        case NAME:
            return QString::fromUtf8("Name");
        case NameColumn::SIZE:
            return QString::fromUtf8("Size");
        case PERCENT:
            return QString::fromUtf8("Percentage");
    }
    return QVariant();
}

QVariant FileBrowserDataModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || dataModel.count() <= index.row() || (role != Qt::DisplayRole && role != Qt::EditRole))
    {
        return QVariant();
    }

    if (index.column() == 0)
    {
        return dataModel[index.row()].name;
    }
    else if (index.column() == 1)
    {
        return dataModel[index.row()].size;
    }
    else if (index.column() == 2)
    {
        return dataModel[index.row()].percent;
    }
    else
        return QVariant();
}



