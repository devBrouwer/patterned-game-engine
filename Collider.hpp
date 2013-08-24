#ifndef COLLIDER_H
#define COLLIDER_H
#include "Visitable.hpp"

class GameObject;
class SphereCollider;
class Collider : public Visitable
{
	protected:
		GameObject * parent;
		float radius;

	public:
		Collider( GameObject * aParent, float aRadius = 1.0f );
		virtual ~Collider();
        GameObject * getParent();
		virtual bool collides( Collider * otherCollider );
		virtual void accept(Visitor * visitor);
		float getRadius();

};

#endif // COLLIDER_H
