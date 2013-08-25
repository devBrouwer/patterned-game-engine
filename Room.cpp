#include "Room.hpp"

//kubus meegeven?
Room::Room(glm::vec3 startPosition, glm::vec3 endPosition, glm::vec3 lichtPositie, glm::vec3 lichtPositie2, std::string muurTexture, std::string vloerTexture, std::string helloRoom) : GameObject ( "Room" , startPosition), endPosition(endPosition), helloRoom(helloRoom)
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

    Mesh * vertical = Mesh::load("models/wall.obj", glm::vec3(1.0,10.0, lengthZ));
    Mesh * horizontal = Mesh::load("models/wall.obj", glm::vec3(lengthX,10.0, 1.0));
    Texture * texture = Texture::load(muurTexture.c_str());

    GameObject * wallLeft = new GameObject("Wall", glm::vec3(sx, -10.0, mz));
    ///loadMesh with wall from sx,sy -> sx,ey
    wallLeft->setMesh(vertical);
    wallLeft->setCollider(new RectangularPrismCollider(wallLeft, glm::vec3(sx, -10.0, sz), glm::vec3(sx +1, 90.0, ez)));
    add(wallLeft);
    wallLeft->setColorMap(texture);

    GameObject * wallUp = new GameObject("Wall", glm::vec3(mx, -10.0, ez));
    wallUp->setMesh(horizontal);
    wallUp->setCollider(new RectangularPrismCollider(wallUp, glm::vec3(sx, -10.0, ez), glm::vec3(ex, 90.0, ez +1)));
    add(wallUp);
    wallUp->setColorMap(texture);

    GameObject * wallRight = new GameObject("Wall", glm::vec3(ex, -10.0, mz));
    wallRight->setMesh(vertical);
    wallRight->setCollider(new RectangularPrismCollider(wallRight, glm::vec3(ex, -10.0, sz), glm::vec3(ex +1, 90.0, ez)));
    add(wallRight);
    wallRight->setColorMap(texture);

    GameObject * wallDown = new GameObject("Wall", glm::vec3(mx, -10.0, sz));
    wallDown->setMesh(horizontal);
    wallDown->setCollider(new RectangularPrismCollider(wallDown, glm::vec3(sx, -10.0, sz), glm::vec3(ex, 90.0, sz+1)));
    add(wallDown);
    wallDown->setColorMap(texture);

    GameObject * floor = new GameObject("Floor", glm::vec3(sx, -10.0, sz));
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

std::string Room::getHelloRoom(){
    return helloRoom;
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
                    if(((GameObject * )*collider)->collides( (GameObject *)*collidee )){
                        result = true;
                        ((GameObject * )*collidee)->collides( (GameObject *)*collider );
                    }
					//result = result || ((GameObject * )*collider)->collides( (GameObject *)*collidee );
				}
			}
		}
	}
	return result; // any collision
}

void Room::remove(GameObject * aChild){
    for (std::vector< GameObject * >::iterator it = children.begin(); it != children.end(); ++it ) {
        if(*it == aChild){
            children.erase(it);
            break;
            //it does break badly
        }
    }

}
