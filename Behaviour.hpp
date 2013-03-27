#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H
#include "Visitable.hpp"

class GameObject;
class Behaviour : public Visitable
{
	protected:
		GameObject * parent;

	public:
		Behaviour( GameObject * aParent );
		virtual ~Behaviour();

		virtual void update( float step );
		virtual void onCollision( GameObject * otherGameObject );
		virtual void accept(Visitor * visitor);

};

#endif // BEHAVIOUR_H
