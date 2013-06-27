#include "GameFactory.hpp"

GameFactory::GameFactory()
{
    //ctor
}

GameFactory::~GameFactory()
{
    //dtor
}

GameObject* GameFactory::createCube(glm::vec3 position, float size, std::string texture){
    GameObject * cube = new GameObject("Cube", position);
        cube->setMesh( Mesh::load( "models/cube.obj", glm::vec3(size, size, size)) );
        cube->setColorMap( Texture::load(texture.c_str()) );
        cube->setCollider( new Collider( cube, size/2 ) );
        ///TODO make cube collider, now it's a sphere collider
    return cube;
}

Door * GameFactory::createDoor(glm::vec3 position, std::string texture, std::string key){
    Door * door = new Door(position, texture, key);
    return door;
}

Chest * GameFactory::createChest(glm::vec3 position, std::string key){
    Chest * chest = new Chest(position, key);
    return chest;
}

Player * GameFactory::createPlayer(glm::vec3 position){
    Player * player = new Player(position);
    player->setBehaviour(new KeysBehaviour( player ));
    return player;
}

Room * GameFactory::createRoom(glm::vec3 startPosition, glm::vec3 endPosition, glm::vec3 lichtPositie, glm::vec3 lichtPositie2, std::string muurTexture, std::string vloerTexture){
    Room * room = new Room(startPosition, endPosition, lichtPositie, lichtPositie2, muurTexture, vloerTexture);
    return room;
}
