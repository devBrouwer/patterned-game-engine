#include "BulletBehaviour.hpp"

BulletBehaviour::BulletBehaviour(Bullet * bullet) : Behaviour(bullet), bullet(bullet)
{
    //ctor
}

BulletBehaviour::~BulletBehaviour()
{
    //dtor
}

void BulletBehaviour::update( float step )
{
	//parent->rotate( step * 45, glm::vec3( 0.0f, 1.0f, 0.0f ) ); // rotates 45° per second
	bullet->translate( step *30 * bullet->getVelocity() );
}


void BulletBehaviour::onCollision(GameObject * otherGameObject){
    bullet->removeMe();
    //otherGameObject handles the rest if neccesary
}
