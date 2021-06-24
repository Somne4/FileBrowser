#ifndef BROWSER_H
#define BROWSER_H
#include <QDir>
#include <QFileInfo>
#include <QTextStream>
#include <QString>
#include <QVector>
#include "SomeData.h"

class FileObserver
{
public:
    FileObserver() {}
    virtual void Update(QList<SomeData> dt) const = 0;
    virtual ~FileObserver() = default;
};


class Browser
{
private:
    FileObserver* observer;
public:
    virtual void Browse(const QString& path) = 0;
    virtual ~Browser() {}

    void Attach(FileObserver* obs)
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
