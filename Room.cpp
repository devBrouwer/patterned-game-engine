#include "Room.hpp"

//kubus meegeven?
Room::Room(std::string aName) : GameObject ( aName )
{
    //ctor
}

Room::~Room()
{
    //dtor
}
bool Room::checkCollisions(){
	bool result = false;
	for (std::vector< GameObject * >::iterator collider = children.begin(); collider != children.end(); ++collider ) {
		if ( ((GameObject * )*collider)->hasCollider() ) {
			for ( std::vector< GameObject * >::iterator collidee = collider+1; collidee != children.end(); ++collidee ) {
				if ( ((GameObject * )*collidee)->hasCollider() ) {
					result = result || ((GameObject * )*collider)->collides( (GameObject *)*collidee );
				}
			}
		}
	}
	return result; // any collision
}
