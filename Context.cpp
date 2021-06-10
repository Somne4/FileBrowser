#include "Context.h"

Context::Context(Browser* strategy) :
    b(strategy) {}


void Context::Browse(const QString& path)//алгоритм стратегии
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
