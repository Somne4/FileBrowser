#include "Context.h"

Context::Context(Browser* strategy) :
    b(strategy) {}


void Context::Browse(const QString& path)//алгоритм стратегии
{
    b->Browse(path);
}

void Context::setStrategy(Browser* strategy)
{
    if (b)
        delete b;
    b = strategy;
}

Context::~Context()
{
    if (b)
        delete b;
}
