#include "RotatingBehaviour.hpp"

#include <iostream>
#include "../glm.hpp"
#include "../GameObject.hpp"
#include "../Player.hpp"

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
	///TODO step meenemen!!
	asteroid->translate( step * asteroid->getVelocity() );
}


void RotatingBehaviour::onCollision(GameObject * otherGameObject){
    if(lastCollider == otherGameObject){
        //DO nothing :)
    }
    else {
        std::cout << "asteroid collision" << std::endl;
        Player * player = dynamic_cast<Player*>(otherGameObject);
        if(player!= NULL){
            asteroid->setOnFire();
            asteroid->setVelocity(glm::vec3(0,0,0));
            ///TODO remove after time...
            //player handles the rest
        }
        else{
            // go in opposite direction
            std::cout << "asteroid velocity is getting opposite..." << std::endl;
            asteroid->setVelocity(glm::vec3(-1.0f*asteroid->getVelocity()));

        }
        lastCollider = otherGameObject;
    }
}
