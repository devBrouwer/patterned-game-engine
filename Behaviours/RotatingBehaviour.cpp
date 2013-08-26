#include "RotatingBehaviour.hpp"

#include <iostream>
#include "../glm.hpp"
#include "../GameObject.hpp"
#include "../Player.hpp"
#include "../Time.hpp"
#include "../Asteroid.hpp"

RotatingBehaviour::RotatingBehaviour( Asteroid * asteroid )
:	Behaviour( asteroid ), asteroid(asteroid)
{
	//ctor
	explosionTime = 0;
}

RotatingBehaviour::~RotatingBehaviour()
{
	//dtor
}

void RotatingBehaviour::update( float step )
{
	//parent->rotate( step * 45, glm::vec3( 0.0f, 1.0f, 0.0f ) ); // rotates 45° per second
	asteroid->translate( step * asteroid->getVelocity() );
	if(explosionTime != 0){
        if(Time::now() - explosionTime > 1.0f){
            //remove asteroid...
            asteroid->removeMe();
        }
    }
}


void RotatingBehaviour::onCollision(GameObject * otherGameObject){
    if(lastCollider == otherGameObject){
        //DO nothing :)
    }
    else {
        lastCollider = otherGameObject;
       // std::cout << "asteroid collision" << std::endl;
        Player * player = dynamic_cast<Player*>(otherGameObject);
        if(player!= NULL){
            asteroid->setOnFire();
            asteroid->setVelocity(glm::vec3(0,0,0));
            explosionTime = Time::now();
            ///TODO play sound
        }
        else{
            Bullet * bullet = dynamic_cast<Bullet*>(otherGameObject);
            if(bullet!= NULL){
                asteroid->setOnFire();
                asteroid->setVelocity(glm::vec3(0,0,0));
                explosionTime = Time::now();
                ///TODO play sound
                ///TODO player score
            }
            else{
                // bounce
                std::cout << "asteroid velocity is getting opposite..." << std::endl;
                asteroid->setVelocity(glm::vec3(-1.0f*asteroid->getVelocity()));
            }
        }
    }
}
