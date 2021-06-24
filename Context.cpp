#include "Context.h"

Context::Context(Browser* strategy) :
    b(strategy) {}


QList<SomeData> Context::Browse(const QString& path)//алгоритм стратегии
{
    if (b)
        return b->Browse(path);
    return QList<SomeData>();
}

void Context::setStrategy(Browser* strategy)
{
    if (b)
        delete b;
    b = strategy;
}

Context::~Context()
{
    delete b;
}
