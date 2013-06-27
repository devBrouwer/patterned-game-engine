#include "Room.hpp"

//kubus meegeven?
Room::Room(glm::vec3 startPosition, glm::vec3 endPosition, glm::vec3 lichtPositie, std::string muurTexture, std::string vloerTexture) : GameObject ( "Room" , startPosition), endPosition(endPosition)
{
    //ctor

    //glm::vec3 startPosition, glm::vec3 endPosition, glm::vec3 lichtPositie, std::string muurTexture, std::string vloerTexture

    //coordinaten voor 4 muren uitrekenen
    float sx = startPosition.x;
    float sy = startPosition.y;

    float ex = endPosition.x;
    float ey = endPosition.y;

    GameObject * wallLeft = new GameObject("Wall", glm::vec3(sx, sy, 0.0));
    ///loadMesh with wall from sx,sy -> sx,ey
    ///add(wallLeft);
    ///wallLeft->setColormap(muurTexture);

    GameObject * wallUp = new GameObject("Wall", glm::vec3(sx, ey, 0.0));
    ///loadMesh with wall from sx,ey -> ex,ey
    ///add(wallUp);
    ///wallUp->setColormap(muurTexture);

    GameObject * wallRight = new GameObject("Wall", glm::vec3(ex, ey, 0.0));
    ///loadMesh with wall from ex,ey -> ex,sy
    ///add(wallRight);
    ///wallRight->setColormap(muurTexture);

    GameObject * wallDown = new GameObject("Wall", glm::vec3(ex, sy, 0.0));
    ///loadMesh with wall from ex,sy -> sx,sy
    ///add(wallDown);
    ///wallDown->setColormap(muurTexture);

    GameObject * floor = new GameObject("Floor", glm::vec3(sx, sy, 0));
    ///loadMesh with floor from sx,sy -> ex,ey
    ///add(floor);
    ///floor->setColormap(floorTexture);

    //maak licht met juiste positie
    Light* light = new Light( "Light", lichtPositie );
    add(light);
}

glm::vec3 Room::getEndPosition(){
    return endPosition;
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
