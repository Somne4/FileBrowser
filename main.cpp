#include <QCoreApplication>
#include "Browser.h"
#include "FolderSize.h"
#include "TypeSize.h"
#include "Context.h"

QTextStream cin(stdin);
QTextStream cout(stdout);

int main()
{
    Browser* p = new FolderSize();
    Context* c = new Context(p);

    QString path;
    cout << "Enter the path to the folder: " << Qt::endl;
    cin.readLineInto(&path, 30);

    if(!path.isEmpty())
    {
        c->Browse(path);
        p = new TypeSize();
        c->setStrategy(p);
        c->Browse(path);
    }
    delete p;
    delete c;
    return 0;
}
