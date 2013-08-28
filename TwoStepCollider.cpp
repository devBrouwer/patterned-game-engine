#include "TwoStepCollider.h"

TwoStepCollider::TwoStepCollider(GameObject * aParent, Collider * broad, Collider * narrow) : Collider(aParent, 0.0f), broad(broad), narrow(narrow)
{
    //ctor
}

TwoStepCollider::~TwoStepCollider()
{
    //dtor
}

bool TwoStepCollider::collides(Collider * otherCollider, bool reportCollision){
    //std::cout << "Two step collider" << std::endl;
    return broad->collides(otherCollider, false) && narrow->collides(otherCollider);
}
