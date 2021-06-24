#include "filesize.h"

qint64 FileSize::getSize(QString const& path)
{
    qint64 res = 0;
    QDir::Filters filters = QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden;
    QDir::SortFlags types = QDir::Name | QDir::Type | QDir::Size;

    QDir dir(path);

        for (const auto& p : dir.entryInfoList(filters, types))
            if (p.isDir())
                {
                    res += getSize(p.absoluteFilePath());
                }
            else res += p.size();
        return res;
}

qint64 FileSize::getSumSize(const QMap<QString, qint64> sum)
{
    qint64 res = 0;
    foreach(qint64 size, sum.values())
        res += size;
    return res;
}
