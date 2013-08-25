#include "Octree.hpp"

#include "GameObject.hpp"

Octree::Octree( const glm::vec3 & aCenter, float aRadius, unsigned int aLevel )
:	center(aCenter), radius(aRadius), level(aLevel)
{
	for ( int i = 0; i < 8; i++ ) {
		children.push_back( NULL );
	}
	divided = false;
}

Octree::~Octree()
{
	//dtor
}


void Octree::add( GameObject * anObject )
{
	// if bottom level store otherwise divide if fits

	if ( level == 0 ) { // if on bottom
		objects.push_back( anObject );
	} else {
        glm::vec3 location = anObject->getLocation();
		// get index for min cube vertex . index is per bit (b0, b1, b2 for subdiv in xyz
		unsigned int minIndex = 1*(location.x - radius >= center.x) + 2*( location.y - radius >= center.y ) + 4*( location.z - radius >= center.z );
		// get index for max cube vertex
		unsigned int maxIndex = 1*(location.x + radius >= center.x) + 2*( location.y + radius >= center.y ) + 4*( location.z + radius >= center.z );
		if ( minIndex == maxIndex ) { // fits in one space
			unsigned int index = minIndex;
			std::cout << level << ": " << anObject->getName() << " fits in child " << index << std::endl;
			if ( ! children[index]) { // wanted space does not exist yet so add it
				children[index] = new Octree( glm::vec3( center.x+radius*( (index&1)-0.5f), center.y+radius*( (index&2)/2-0.5f), center.z+radius*( (index&4)/4-0.5f)), radius / 2, level-1 );
			}
			children[index]->add( anObject ); // add object to space
		} else { // when does not fit in child, put it here
			objects.push_back( anObject ); // does not fit in any child so store here
		}
	}
}

void Octree::gatherObjects( std::vector<GameObject *> & target ) {
	for ( unsigned int i = 0; i < objects.size(); i++ ) {
		target.push_back( objects[i] );
	}
	for ( unsigned int i = 0; i < children.size(); i++ ) {
		if ( children[i] ) {
			children[i]->gatherObjects( target );
		}
	}
}

void Octree::print( std::string pre )
{
	std::cout << pre << level << " Node : " << center << "\t";
	for ( unsigned int i = 0; i < objects.size(); i++ ) {
		std::cout << objects[i] << ", ";
	}
	std::cout << std::endl;

	for ( int i = 0; i < 8; i++ ) {
		if ( children[i] ) {
			children[i]-> print( pre+"  " );
		}
	}
}

unsigned int Octree::detectCollisions() {
	unsigned int count = 0;
	// detect agains objects in this spaces and in children
	for ( unsigned int i = 0; i < objects.size(); i++ ) { // check every objects in this space
		GameObject * collider = objects[i];
		for ( unsigned int j = i+1; j < objects.size(); j++ ) { // check collider agains otyher object in this space
			GameObject * collidee = objects[j];
			count ++;
			if ( collider->collides( collidee ) ) {
				std::cout << "  Collision " << collider->getName() << " = " << collidee->getName() << std::endl;
			}
		}

		// detect collider  against children content
		for ( int i = 0; i < 8; i++ ) {
			Octree * child = children[i];
			if ( child ) {
				count += child->detectCollisions( collider );
			}
		}
	}

	// let children detect internal collisions
	for ( int i = 0; i < 8; i++ ) {
		Octree * child = children[i];
		if ( child ) {
			count += child->detectCollisions();
		}
	}
	return count;
}

unsigned int Octree::detectCollisions( GameObject * collider ) {
	unsigned int count = 0;
	// checking against own objects
	for ( unsigned int j = 0; j < objects.size(); j++ ) {
		GameObject * collidee = objects[j];
		if ( collider != collidee ) { // do not check against itself
			count ++; // counting checks
			if ( collider->collides( collidee ) ) {
				std::cout << "  Collision " << collider->getName() << " = " << collidee->getName() << std::endl;
			}
		}
	}
	// let children check as wel
	for ( int i = 0; i < 8; i++ ) {
		Octree * child = children[i];
		if ( child ) {
			count += child->detectCollisions( collider );
		}
	}
	return count;
}
