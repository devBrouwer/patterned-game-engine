#ifndef VISITABLE_H
#define VISITABLE_H

#include "Visitor.hpp"

class Visitor;

class Visitable
{
    public:
        Visitable();
        virtual ~Visitable();
        virtual void accept(Visitor * visitor) = 0;
    protected:
    private:
};

#endif // VISITABLE_H
