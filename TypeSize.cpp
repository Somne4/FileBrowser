#include "TypeSize.h"

void TypeSize::getFileType(const QString& path, QMap<QString, qint64>& TypeList)
{
    QDir dir(path);
    QDir::Filters filters = QDir::AllEntries| QDir::NoDotAndDotDot | QDir::Hidden;
    QDir::SortFlags types = QDir::Name | QDir::Type | QDir::Size;
    for (const auto p : dir.entryInfoList(filters, types))
    {
        if (p.isDir())
        {
            getFileType(p.absoluteFilePath(), TypeList);
        }
         else
        {
            if (TypeList.keys().contains(p.suffix().toLower()))
            {
                TypeList[p.suffix()] += p.size();//suffix - расширение файла
            }
            else
            {
                TypeList.insert(p.suffix().toLower(), p.size());
            }
        }
   }
}

QMap<QString, double> TypeSize::getTypePercent(qint64& size, QMap<QString, qint64>& TypeList)
{
    QMap<QString, double> ListPercent;
    double percent;

    for (auto p = TypeList.begin(); p != TypeList.end(); p++)
    {
        if (p.value() == 0)
            percent = 0;
        else
        {
        percent = double(p.value() * 100) / size;
        if (percent < 0.01)
            percent = -10;
        }
        ListPercent.insert(p.key(), percent);
    }
    return ListPercent;
}

QList<QPair<double, QString>> TypeSize::Sorting(const QMap<QString, double>& TypePercent)
{
    QList<QPair<double, QString>> res;
    for (auto p : TypePercent.keys())
    {
        res.append(QPair<double, QString>(TypePercent[p], p));
    }
    sort(res.begin(), res.end(), std::greater<QPair<double, QString>>());
    return res;
}

QList<SomeData> TypeSize::Browse(const QString& path)
{
    QList<SomeData> data;
    QMap<QString, qint64> TypeList;
    getFileType(path, TypeList);
    auto SumSize = FileSize::getSumSize(TypeList);
    auto percent = getTypePercent(SumSize, TypeList);
    auto sorting = Sorting(percent);
    for (auto x : sorting)
    {
        if (x.first == -10)
        {
            data.append(SomeData(x.second, QString::number(TypeList.value(x.second)), QString("< 0.01 %")));
        } else
        {
        data.append(SomeData("." + x.second, QString::number(TypeList.value(x.second)), QString::number(x.first, 'f', 2).append(" %")));
        }
    }
    return data;
}
