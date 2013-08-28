#include "MeshCollider.hpp"

MeshCollider::MeshCollider(GameObject * aParent) : Collider(aParent)
{
    //ctor
}

MeshCollider::~MeshCollider()
{
    //dtor
}

bool MeshCollider::collides(Collider * otherCollider, bool reportCollision){
    std::cout << "NOT implemented yet" <<std::endl;
    return false;
}