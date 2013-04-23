#include "Ruimte.hpp"

//kubus meegeven?
Ruimte::Ruimte(std::string aName) : GameObject ( aName )
{
    //ctor
}

Ruimte::~Ruimte()
{
    //dtor
}
bool Ruimte::checkCollisions(){
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
