#ifndef BROWSER_H
#define BROWSER_H
#include <QDir>
#include <QFileInfo>
#include <QTextStream>
#include <QString>
#include <QVector>

class Browser
{
public:
    virtual void Browse(const QString& path) = 0;
    virtual ~Browser() {}
};

#endif // BROWSER_H

