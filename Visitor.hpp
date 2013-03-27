#ifndef VISITOR_H
#define VISITOR_H
#include <iostream>

class World;
class Camera;
class Light;
class GameObject;
class Mesh;
class Behaviour;
class Collider;

class Visitor
{
    public:
        Visitor();
        virtual ~Visitor();
        virtual void visit(World * world) =0;
        virtual void visit(Camera * camera) =0;
        virtual void visit(Light * light) =0;
        virtual void visit(GameObject * gameobject) =0;
        virtual void visit(Mesh * mesh) =0;
        virtual void visit(Behaviour * behaviour) =0;
        virtual void visit(Collider * collider) =0;
    protected:
    private:
};

#endif // VISITOR_H
