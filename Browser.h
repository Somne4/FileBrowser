#ifndef BROWSER_H
#define BROWSER_H
#include <QDir>
#include <QFileInfo>
#include <QTextStream>
#include <QString>
#include <QVector>
#include "Observer.h"

class SomeData
{
public:
SomeData(const QString nm, const QString sz, const QString prc, qreal sh)
{
    name = nm;
    size = sz;
    percent = prc;
    share = sh;
}
QString name;
QString size;
QString percent;
qreal share;
};

class Browser
{
private:
    Observer* obs;
public:
    virtual QList<SomeData> Browse(const QString& path) = 0;
    virtual ~Browser() {}

    void Attach(Observer* obs)
    {
        if (obs)
            observer = obs;
    }

    void OnFinish(const QList<SomeData>& dt) const
    {
        observer->Update(dt);
    }
};

#endif // BROWSER_H
