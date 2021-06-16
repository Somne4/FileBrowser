#ifndef CONTEXT_H
#define CONTEXT_H
#include "Browser.h"

class Context // вызов класса Browser
{
private:
    Browser *b;
public:
    Context() = default;
    explicit Context(Browser* strategy);
    ~Context();
    QList<SomeData> Browse(const QString& path);
    void setStrategy(Browser* strategy);
};

#endif // CONTEXT_H
