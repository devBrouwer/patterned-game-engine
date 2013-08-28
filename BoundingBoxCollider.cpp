#include "BoundingBoxCollider.hpp"

BoundingBoxCollider::BoundingBoxCollider(GameObject * aParent, glm::vec3 start, glm::vec3 end): Collider(aParent, 0.0f), start(start), end(end)
{
    //ctor
}

BoundingBoxCollider::~BoundingBoxCollider()
{
    //dtor
    //for elk hoekpunt..
    //bereken positie van hoekpunt:
    //glm::vec4 positieHoekpunt = parent->getTransform()*glm::vec4(hoekpunt.x, hoekpunt.y, hoekpunt.z, 1.0f)
        //bereken afstand tot hoekpunt1 en hoekpunt2
        //kijk of afstand < radius*2
    //kijk of het punt er al binnnen ligt
}

bool BoundingBoxCollider::collides(Collider * otherCollider ){
    std::cout << "NOT IMPLEMENTED YET" << std::endl;
    return false;
}

