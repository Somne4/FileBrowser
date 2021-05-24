#ifndef CONTEXT_H
#define CONTEXT_H
#include "Browser.h"

class Context // вызов класса Browser
{
private:
    Browser *b;
public:
    explicit Context(Browser* strategy);
    ~Context();
    void Browse(const QString& path);
    void setStrategy(Browser* strategy);
};

#endif // CONTEXT_H
