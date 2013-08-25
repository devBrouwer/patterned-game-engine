#include "RectangularPrismCollider.hpp"

RectangularPrismCollider::RectangularPrismCollider(GameObject * aParent, glm::vec3 start, glm::vec3 end) : Collider(aParent), start(start), end(end)
{
    //ctor
}

RectangularPrismCollider::~RectangularPrismCollider()
{
    //dtor
}

bool RectangularPrismCollider::collides( Collider * otherCollider ){
    glm::vec3 location = otherCollider->getParent()->getLocation();
    float radius = otherCollider->getRadius();

    // linksondervoor == sx, sy, sz
    // rechtsondervoor == ex, sy, sz
    // linksonderachter == sx, sy, ez
    // rechtsonderachter == ex, sy, ez
    // linksbovenvoor == sx, ey, sz
    // rechtsbovenvoor == ex, ey, sz
    // linksbovenachter == sx, ey, ez
    // rechtsbovenachter == ex, ey, ez

    if( ((start.x <= location.x && location.x <= end.x ) ||
         ( end.x <= location.x && location.x <= start.x )) &&
      ((start.y <= location.y && location.y <= end.y) ||
       (end.y <= location.y && location.y <= start.y)) &&
      ((start.z <= location.z && location.z <= end.z) ||
       (end.z <= location.z && location.z <= start.z))){
        //std::cout << getParent()->getName() << " Hits " << otherCollider->getParent()->getName() << std::endl;
        getParent()->onCollision(otherCollider->getParent());
        otherCollider->getParent()->onCollision(getParent());
        return true;
    }
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
