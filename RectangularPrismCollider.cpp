#include "RectangularPrismCollider.hpp"

RectangularPrismCollider::RectangularPrismCollider(GameObject * aParent, glm::vec3 rectangle) : Collider(aParent), rectangle(rectangle)
{
    //ctor
}

RectangularPrismCollider::~RectangularPrismCollider()
{
    //dtor
}

bool RectangularPrismCollider::collides( Collider * otherCollider ){
    ///TODO aanpassen
    glm::vec3 location = parent->getLocation();
	//glm::vec3 otherLocation = otherCollider->parent->getLocation();
	//float distance = glm::distance( location, otherLocation );
	//if ( distance < radius + otherCollider->radius ) {
	//	std::cout << parent->getName() << " Hits " << otherCollider->parent->getName() << std::endl;
	//	return true;
	//};
	return false;
}

void RectangularPrismCollider::accept(Visitor * visitor){
    visitor->visit(this);
}
