#ifndef FOLDERSIZE_H
#define FOLDERSIZE_H
#include "Browser.h"
#include "filesize.h"

class FolderSize : public Browser // Размер файлов папке, проценты, сортировка по возрастанию и вывод
{
private:
    qint64 getSizeDir(const QString& path);
    QMap<QString, qint64> getFolderSize(const QString& path);
    QMap<QString, double> getListPercents(qint64& size, QMap<QString, qint64>& FoldersList);
    QList<QPair<double, QString>> Sorting(const QMap<QString, double>& FolderPercent);
public:
    explicit FolderSize() {};
    virtual ~FolderSize() {};
    QList<SomeData> Browse(const QString& path) override;
};

#endif // FOLDERSIZE_H
