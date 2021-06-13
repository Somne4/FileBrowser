#ifndef TYPESIZE_H
#define TYPESIZE_H
#include "Browser.h"
#include "filesize.h"

class TypeSize : public Browser
{
private:
    void getFileType(const QString& path, QMap<QString, qint64>& TypeList);
    QMap<QString, double> getTypePercent(qint64& size, QMap<QString, qint64>& TypeList);
    QList<QPair<double, QString>> Sorting(const QMap<QString, double>& TypePercent);
    void PrintOperator(const QMap<QString, qint64>& TypeList, const QList<QPair<double, QString>> TypePercent);
public:
    explicit TypeSize() {};
    virtual ~TypeSize() {};
    QList<SomeData> Browse(const QString& path) override;
};

#endif // TYPESIZE_H
