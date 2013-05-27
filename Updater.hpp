#ifndef UPDATER_HPP
#define UPDATER_HPP

#include "Visitor.hpp"
#include "Behaviour.hpp"


class Updater : public Visitor
{
    public:
        Updater();
        virtual ~Updater();
        virtual void visit(World * world);
        virtual void visit(Camera * camera);
        virtual void visit(Light * light);
        virtual void visit(GameObject * gameobject);
        virtual void visit(Mesh * mesh);
        virtual void visit(Behaviour * behaviour, float );
        virtual void visit(Collider * collider);
    protected:
    private:
};

#endif // UPDATER_HPP
