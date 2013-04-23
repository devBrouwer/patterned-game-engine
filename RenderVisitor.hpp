#ifndef RENDERVISITOR_H
#define RENDERVISITOR_H

#include "Visitor.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "GameObject.hpp"
#include "Mesh.hpp"
#include "Renderer.hpp"



class RenderVisitor : public Visitor
{
    public:
        RenderVisitor(Renderer * aRenderer);
        virtual ~RenderVisitor();
        virtual void visit(World * world);
        virtual void visit(Camera * camera);
        virtual void visit(Light * light);
        virtual void visit(GameObject * gameobject);
        virtual void visit(Mesh * mesh);
        virtual void visit(Collider * c);
        virtual void visit(Behaviour * b);
        //virtual void visit(Visitable * visitable);
    protected:
    private:
        Renderer * renderer;
};

#endif // RENDERVISITOR_H
