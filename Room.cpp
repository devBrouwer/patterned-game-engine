#include "Room.hpp"

//kubus meegeven?
Room::Room(glm::vec3 startPosition, glm::vec3 endPosition, glm::vec3 lichtPositie, glm::vec3 lichtPositie2, std::string muurTexture, std::string vloerTexture, std::string helloRoom) : GameObject ( "Room" , startPosition), endPosition(endPosition), helloRoom(helloRoom)
{
    removeList = new std::vector<GameObject *>();
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
    wallLeft->setCollider(new WallCollider(wallLeft, glm::vec3(sx -5.0f, -10.0, sz), glm::vec3(sx +1, 90.0, ez)));
    add(wallLeft);
    wallLeft->setColorMap(texture);

    GameObject * wallUp = new GameObject("Wall", glm::vec3(mx, -10.0, ez));
    wallUp->setMesh(horizontal);
    wallUp->setCollider(new WallCollider(wallUp, glm::vec3(sx, -10.0, ez -5.0f), glm::vec3(ex, 90.0, ez +1)));
    add(wallUp);
    wallUp->setColorMap(texture);

    GameObject * wallRight = new GameObject("Wall", glm::vec3(ex, -10.0, mz));
    wallRight->setMesh(vertical);
    wallRight->setCollider(new WallCollider(wallRight, glm::vec3(ex +5.0f, -10.0, sz), glm::vec3(ex -1, 90.0, ez)));
    add(wallRight);
    wallRight->setColorMap(texture);

    GameObject * wallDown = new GameObject("Wall", glm::vec3(mx, -10.0, sz));
    wallDown->setMesh(horizontal);
    wallDown->setCollider(new WallCollider(wallDown, glm::vec3(sx, -10.0, sz+5.0f), glm::vec3(ex, 90.0, sz-1)));
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

void Room::remove(GameObject * gameObject){
    removeList->push_back(gameObject);
}

void Room::removeThings(){
    int end = removeList->size();
    for(int i = 0; i < end; ++i ){
        GameObject * removeMe = removeList->at(i);
        for(std::vector< GameObject * >::iterator it = children.begin(); it != children.end() ; ++it) {
            if(*it == removeMe){
                children.erase(it);
                //it does break badly
                break;
            }
        }
        //removeList->erase(removeList->begin());
        delete removeMe;
    }
    removeList->clear();
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

GameObject * Room::pick(glm::vec2 mouseCoords, Picker * picker){
    picker->pick(mouseCoords);
    for (std::vector< GameObject * >::iterator collider = children.begin(); collider != children.end(); ++collider ) {
		if ( ((GameObject * )*collider)->hasCollider() ) {
                //TODO
                if(picker->hits((*collider)->getLocation(),(*collider)->getCollider()->getRadius())){
                    return *collider;
                }
		}
    }
    return NULL;
}

bool Room::checkCollisions(){
	bool result = false;
	for (std::vector< GameObject * >::iterator collider = children.begin(); collider != children.end(); ++collider ) {
		if ( ((GameObject * )*collider)->hasCollider() ) {
			for ( std::vector< GameObject * >::iterator collidee = collider+1; collidee != children.end(); ++collidee ) {
				//if(collider != collidee){
                    if ( ((GameObject * )*collidee)->hasCollider() ) {
                        if(((GameObject * )*collider)->collides( (GameObject *)*collidee )){
                            result = true;
                            ((GameObject * )*collidee)->collides( (GameObject *)*collider );
                        }
                        //result = result || ((GameObject * )*collider)->collides( (GameObject *)*collidee );
                    }
				//}
			}
		}
	}
	return result; // any collision
}
