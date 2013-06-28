#include "Door.hpp"

Door::Door(glm::vec3 position, std::string texture, std::string key, World * aWorld) : GameObject("Door", position), key(key), world(aWorld)
{
    //ctor
    //maak mesh aan met texture
    setMesh( Mesh::load( "models/door.obj" ) );
    setColorMap( Texture::load( texture.c_str() ) );
    room1 = 0;
    room2 = 0;
    room3 = 0;
    opened = false;
}

Door::~Door()
{
    //dtor
}

void Door::setOpened(bool aOpened){
    opened = aOpened;
}

bool Door::isOpened(){
    return opened;
}

std::string Door::getKey(){
    return key;
}

Room * Door::getRoom1(){
    return room1;
}

Room * Door::getRoom2(){
    return room2;
}

Room * Door::getRoom3(){
    return room3;
}

void Door::setRoom1(Room * aRoom1){
    room1 = aRoom1;
}

void Door::setRoom2(Room * aRoom2){
    room2 = aRoom2;
}

void Door::setRoom3(Room * aRoom3){
    room3 = aRoom3;
}

World * Door::getWorld(){
    return world;
}
