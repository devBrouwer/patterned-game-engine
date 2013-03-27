#include "RenderVisitor.hpp"

RenderVisitor::RenderVisitor()
{
    //ctor
    counter = 0;
}

RenderVisitor::~RenderVisitor()
{
    //dtor
}

void RenderVisitor::visit(World * world){
    ++counter;
    std::cout << "WORLD: " << counter << std::endl;
}

void RenderVisitor::visit(Camera * camera){
    ++counter;
    std::cout << "CAMERA: " << counter << std::endl;
}

void RenderVisitor::visit(Light * light){
    ++counter;
    std::cout << "LIGHT: " << counter << std::endl;
}

void RenderVisitor::visit(GameObject * gameObject){
    ++counter;
    std::cout << "GAMEOBJECT: " << counter << std::endl;
}

void RenderVisitor::visit(Mesh * mesh){
    ++counter;
    std::cout << "MESH: " << counter << std::endl;
}

void RenderVisitor::visit(Behaviour * b){
    std::cout << "BEHAVIOUR DOES NOT COUNT: " << counter << std::endl;
}
void RenderVisitor::visit(Collider * c){
    std::cout << "COLLIDER DOES NOT COUNT: " << counter << std::endl;
}
