#ifndef BROWSER_H
#define BROWSER_H
#include <QDir>
#include <QFileInfo>
#include <QTextStream>
#include <QString>
#include <QVector>

class SomeData
{
public:
SomeData(const QString nm, const QString sz, const QString prc)
{
    name = nm;
    size = sz;
    percent = prc;
}
QString name;
QString size;
QString percent;
};

class Browser
{
public:
    virtual QList<SomeData> Browse(const QString& path) = 0;
    virtual ~Browser() {}
};

#endif // BROWSER_H
