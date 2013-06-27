#include "Door.hpp"

Door::Door(glm::vec3 position, std::string texture, std::string key) : GameObject("Door", position), key(key)
{
    //ctor
    //maak mesh aan met texture
    setMesh( Mesh::load( "models/door.obj" ) );
    setColorMap( Texture::load( texture.c_str() ) );
}

Door::~Door()
{
    //dtor
}

std::string Door::getKey(){
    return key;
}
