#include "Room.hpp"

//kubus meegeven?
Room::Room(glm::vec3 startPosition, glm::vec3 endPosition, glm::vec3 lichtPositie, glm::vec3 lichtPositie2, std::string muurTexture, std::string vloerTexture) : GameObject ( "Room" , startPosition), endPosition(endPosition)
{
    //ctor

    //glm::vec3 startPosition, glm::vec3 endPosition, glm::vec3 lichtPositie, std::string muurTexture, std::string vloerTexture

    //coordinaten voor 4 muren uitrekenen
    float sx = startPosition.x;
    float sz = startPosition.z;

    float ex = endPosition.x;
    float ez = endPosition.z;

    float mx = (ex + sx) /2;
    float mz = (ez + sz) /2;

    float lengthX = ex - sx;
    float lengthZ = ez - sz;

    Mesh * vertical = Mesh::load("models/wall.obj", glm::vec3(1.0,1.0, lengthZ));
    Mesh * horizontal = Mesh::load("models/wall.obj", glm::vec3(lengthX,1.0, 1.0));
    Texture * texture = Texture::load(muurTexture.c_str());

    GameObject * wallLeft = new GameObject("Wall", glm::vec3(sx, 0.0, sz));
    ///loadMesh with wall from sx,sy -> sx,ey
    wallLeft->setMesh(vertical);
    /// wallLeft->setCollider(new RectangularPrismCollider(wallLeft, glm::vec3(1.0,10.0, lengthZ)));
    add(wallLeft);
    wallLeft->setColorMap(texture);

    GameObject * wallUp = new GameObject("Wall", glm::vec3(sx, 0.0, ez));
    wallUp->setMesh(horizontal);
    /// wallLeft->setCollider(new RectangularPrismCollider(wallLeft, glm::vec3(1.0,10.0, lengthZ)));
    add(wallUp);
    wallUp->setColorMap(texture);

    GameObject * wallRight = new GameObject("Wall", glm::vec3(ex, 0.0, sz));
    wallRight->setMesh(vertical);
    /// wallLeft->setCollider(new RectangularPrismCollider(wallLeft, glm::vec3(1.0,10.0, lengthZ)));
    add(wallRight);
    wallRight->setColorMap(texture);

    GameObject * wallDown = new GameObject("Wall", glm::vec3(sx, 0.0, sz));
    wallDown->setMesh(horizontal);
    /// wallLeft->setCollider(new RectangularPrismCollider(wallLeft, glm::vec3(1.0,10.0, lengthZ)));
    add(wallDown);
    wallDown->setColorMap(texture);

    GameObject * floor = new GameObject("Floor", glm::vec3(sx, 0.0, sz));
    floor->setMesh(Mesh::load("models/floor.obj", glm::vec3(lengthX, 1.0, lengthZ)));
    add(floor);
    floor->setColorMap(Texture::load(vloerTexture.c_str()));

    //maak licht met juiste positie
    Light* light = new Light( "Light", lichtPositie );
    add(light);
    Light* light2 = new Light( "Light2", lichtPositie2 );
    add(light2);
}

glm::vec3 Room::getEndPosition(){
    return endPosition;
}

void Room::add( GameObject * child )
{
	assert( child != NULL );
	children.push_back( child );
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
