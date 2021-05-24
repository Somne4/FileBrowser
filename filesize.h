#ifndef FILESIZE_H
#define FILESIZE_H
#include "Browser.h"

namespace FileSize //inline функции
{
    qint64 getSize(QString const& path);
    qint64 getSumSize(const QMap<QString, qint64> sum);
};

#endif // FILESIZE_H
