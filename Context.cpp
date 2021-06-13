#include "Context.h"

Context::Context(Browser* strategy) :
    b(strategy) {}


QList<SomeData> Context::Browse(const QString& path)//алгоритм стратегии
{
    if (b)
    b->Browse(path);
}

void Context::setStrategy(Browser* strategy)
{
    b = strategy;
}

Context::~Context()
{}
