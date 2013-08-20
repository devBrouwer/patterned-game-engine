#include "Chest.hpp"

Chest::Chest(glm::vec3 position, std::string key) : GameObject("Chest", position), key(key)
{
    //ctor
    opened = false;
    //Mesh * mesh = Mesh::load
    setMesh( Mesh::load( "models/spaceship.obj" ) );
    setColorMap( Texture::load( "models/chest.jpg" ) );
}

Chest::~Chest()
{
    //dtor
}

void Chest::open(){
    opened = true;
}

std::string Chest::getKey(){
    return key;
}

bool Chest::getOpened(){
    return opened;
}

