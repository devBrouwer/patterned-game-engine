#include "RenderVisitor.hpp"
#include "glm.hpp"

RenderVisitor::RenderVisitor(Renderer * aRenderer) : renderer(aRenderer)
{
    //ctor
}

RenderVisitor::~RenderVisitor()
{
    //dtor
}

void RenderVisitor::visit(World * world){
    renderer->initDraw();
}

void RenderVisitor::visit(Camera * camera){
	renderer->setProjection( camera->getProjection() ); // model = cam to worldspace so inverse for world->camspace
	renderer->setView( glm::inverse( camera->getTransform() ) ); // model = cam to worldspace so inverse for world->camspace
}

void RenderVisitor::visit(Light * light){
    renderer->setLight( light->getLocation() );
}

void RenderVisitor::visit(GameObject * gameObject){
    if(gameObject->hasMesh()){
        renderer->setModel( gameObject->getTransform() );
        if( Texture * colormap = gameObject->getColorMap() ){
            renderer->setColorMap(colormap);
        }
    }
}

void RenderVisitor::visit(Mesh * mesh){
    renderer->draw( mesh->size(), mesh->getIndicesBuffer(), mesh->getVerticesBuffer(), mesh->getNormalsBuffer(), mesh->getUvsBuffer() );
}

void RenderVisitor::visit(Behaviour * b){}
void RenderVisitor::visit(Collider * c){}
