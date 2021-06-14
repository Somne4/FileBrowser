#ifndef FILEBROWSERDATAMODEL_H
#define FILEBROWSERDATAMODEL_H
#include <QAbstractTableModel>
#include <QList>
#include <QLocale>
#include "Browser.h"

class FileBrowserDataModel : public QAbstractTableModel
{
    Q_OBJECT
private:
    enum NameColumn //Определим перечисление NameColumn для индексации столбцов нашей таблицы.
    {
        NAME = 0,
        SIZE,
        PERCENT
    };
    QList<SomeData> dataModel; //Представим данные модели в виде списка.
public:
    FileBrowserDataModel() = default;
    FileBrowserDataModel(const QList<SomeData>& dt, QObject* parent = nullptr);
    void setModel(const QList<SomeData>& dt);
    ~FileBrowserDataModel() = default;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};

#endif // FILEBROWSERDATAMODEL_H
