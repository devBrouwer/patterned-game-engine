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
    private:
        Asteroid * asteroid;

};

#endif // RARTATINGBEHAVIOUR_H
