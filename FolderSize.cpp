#include "FolderSize.h"

qint64 FolderSize::getSizeDir(const QString& path)
{
    qint64 res = 0;
    QDir dir(path);
    QDir::Filters filters = QDir::Files| QDir::NoDotAndDotDot | QDir::Hidden;
    QDir::SortFlags types = QDir::Name | QDir::Type;
    for (auto p : dir.entryInfoList(filters, types))
        res += p.size();
    return res;
}

QMap<QString, qint64> FolderSize::getFolderSize(const QString& path)
{
    QFileInfo folderInfo(path);
    QMap<QString, qint64> FolderSizeList;
    auto path_ = folderInfo.absoluteFilePath();
    FolderSizeList.insert(path_, getSizeDir(path_));
    QDir::Filters filters = QDir::Dirs | QDir::NoDotAndDotDot | QDir::Hidden;
    QDir::SortFlags types = QDir::Name | QDir::Type;
    for (auto p : QDir(path).entryInfoList(filters, types))
    {
        auto _path = p.absoluteFilePath();
        FolderSizeList.insert(_path, FileSize::getSize(_path));
    }
    return FolderSizeList;
}

QMap<QString, double> FolderSize::getListPercents(qint64& size, QMap<QString, qint64>& FolderList)
{
    QMap<QString, double> PercentList;
    double percent;
    for (auto p = FolderList.begin(); p != FolderList.end(); p++)
    {
        if (p.value() == 0)
            percent = 0;
        else
        {
            percent = double(p.value() * 100) / size;
            if (percent < 0.01)
                percent = -10;
        }
        PercentList.insert(p.key(), percent);
    }
    return PercentList;
}

QList<QPair<double, QString>> FolderSize::Sorting(const QMap<QString, double>& FolderPercent)
{
    QList<QPair<double, QString>> res;
    for (auto p : FolderPercent.keys())
    {
      res.append(QPair<double, QString>(FolderPercent[p], p));
    }
    sort(res.begin() + 1, res.end(), std::greater<QPair<double, QString>>()); // greater - выполняет операцию сравнения для своих аргументов
    return res;
}


void FolderSize::Browse(const QString& path)
{
    QList<SomeData> data;
    auto FolderList = getFolderSize(path);
    auto SumSize = FileSize::getSumSize(FolderList);
    auto percent = getListPercents(SumSize, FolderList);
    auto sorting = Sorting(percent);
    for (auto x : sorting)
    {
        if (x.first == -10)
        {
            data.append(SomeData(x.second, QString::number(FolderList.value(x.second)), QString("< 0.01 %"), (qreal)FolderList.value(x.second)/ SumSize));
        } else
        {
            data.append(SomeData(x.second, QString::number(FolderList.value(x.second)), QString::number(x.first, 'f', 2).append(" %"), (qreal)FolderList.value(x.second)/ SumSize));
        }
    }
    OnFinish(QList<SomeData>(data));

}


