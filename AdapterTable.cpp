#include "AdapterTable.h"

AdapterTable::AdapterTable(QLayout* layout)
{
    dataModel = new FileBrowserDataModel();
    view = new QTableView();
    view->setModel(dataModel);
    layout->addWidget(view);
}

void AdapterTable::Update(QList<SomeData> dt) const
{
    dataModel->setModel(dt);
}

AdapterTable::~AdapterTable()
{
    delete dataModel;
    delete view;
}
