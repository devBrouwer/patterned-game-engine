#ifndef RARTATINGBEHAVIOUR_H
#define RARTATINGBEHAVIOUR_H

#include "../Behaviour.hpp"
#include "../Asteroid.hpp"

class RotatingBehaviour : public Behaviour
{
	public:
		RotatingBehaviour( Asteroid * asteroid );
		virtual ~RotatingBehaviour();

		virtual void update( float step );
		virtual void onCollision(GameObject * otherGameObject);
    private:
        Asteroid * asteroid;
        GameObject * lastCollider;
        float explosionTime;

};

#endif // RARTATINGBEHAVIOUR_H
