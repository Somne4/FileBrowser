#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QItemSelection>
#include <QFileSystemModel>
#include "FileBrowserDataModel.h"
#include <memory>
#include "Context.h"
#include <QMainWindow>
#include <QFileSystemModel>
#include <QDebug>
#include "FolderSize.h"
#include "TypeSize.h"
#include "Adapter.h"
#include "AdapterTable.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QMainWindow *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QFileSystemModel* dirModel;
    FileBrowserDataModel* fileModel;
    QString path;   
    Browser* Folders;
    Browser* Types;
    Browser* Grouping;
    FileObserver* View;
    FileObserver* TableAdapter;
    FileObserver* bar;
    FileObserver* pie;
public slots:
    void ChoiceStrategy(int index);
    void selectionChangedSlot(const QItemSelection& selected, const QItemSelection& deselected);
    void selectionDisplay(int index);
};

#endif // MAINWINDOW_H



