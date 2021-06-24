#ifndef ADAPTERTABLE_H
#define ADAPTERTABLE_H
#include "FileBrowserDataModel.h"
#include <QTableView>
#include <QLayout>
#include <QHeaderView>

class AdapterTable : public FileObserver
{
private:
    FileBrowserDataModel* dataModel;
    QTableView* view;
public:
    explicit AdapterTable(QLayout* layout);
    ~AdapterTable();
    void Update(QList<SomeData> dt) const;
};

#endif // ADAPTERTABLE_H
