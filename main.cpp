#include "Browser.h"
#include "FolderSize.h"
#include "TypeSize.h"
#include "Context.h"
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow p;
    p.show();

    return a.exec();
}

