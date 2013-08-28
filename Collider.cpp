#include <iostream>
#include "Collider.hpp"
#include "GameObject.hpp"

Collider::Collider( GameObject * aParent, float aRadius )
:	parent(aParent), radius( aRadius )
{
	//ctor
}

Collider::~Collider()
{
	//dtor
}

bool Collider::collides( Collider * otherCollider, bool reportCollision)
{
	//std::cout << "Check CD for " << parent->getName() << std::endl;
	glm::vec3 location = parent->getLocation();
	glm::vec3 otherLocation = otherCollider->parent->getLocation();
	float distance = glm::distance( location, otherLocation );
	if ( distance < radius + otherCollider->radius ) {
		//std::cout << parent->getName() << " Hits " << otherCollider->parent->getName() << std::endl;
        if(reportCollision){
            parent->onCollision(otherCollider->parent);
        }
        //otherCollider->getParent()->onCollision(getParent());
		return true;
	};
	return false;
}

void Collider::accept(Visitor * visitor){
    visitor->visit(this);
}

GameObject * Collider::getParent(){
    return parent;
}

float Collider::getRadius(){
    return radius;
}

