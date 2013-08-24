#include "RotatingBehaviour.hpp"

#include <iostream>
#include "../glm.hpp"
#include "../GameObject.hpp"

RotatingBehaviour::RotatingBehaviour( Asteroid * asteroid )
:	Behaviour( asteroid ), asteroid(asteroid)
{
	//ctor
}

RotatingBehaviour::~RotatingBehaviour()
{
	//dtor
}

void RotatingBehaviour::update( float step )
{
	//parent->rotate( step * 45, glm::vec3( 0.0f, 1.0f, 0.0f ) ); // rotates 45° per second
	asteroid->translate( asteroid->getVelocity() );
}
