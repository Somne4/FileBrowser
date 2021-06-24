#ifndef SOMEDATA_H
#define SOMEDATA_H
#include <QString>

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

#endif // SOMEDATA_H
