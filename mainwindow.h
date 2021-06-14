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

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    enum class Strategy
    {
        Folder,
        Type
    };
    explicit MainWindow(QMainWindow *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QFileSystemModel* dirModel;
    FileBrowserDataModel* fileModel;
    Context* p;
    QList<SomeData> data;
    QString path;
    Strategy strategy_;
};

#endif // MAINWINDOW_H



