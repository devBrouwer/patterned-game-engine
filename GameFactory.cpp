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
        cube->setCollider( new Collider( cube ) );
        ///TODO make cube collider, now it's a sphere collider
    return cube;
}

Door * GameFactory::createDoor(glm::vec3 position, std::string texture, std::string key, World * w){
    Door * door = new Door(position, texture, key, w);
    door->setCollider(new Collider(door));
    return door;
}

Chest * GameFactory::createChest(glm::vec3 position, std::string key){
    Chest * chest = new Chest(position, key);
    chest->setCollider(new Collider(chest));
    return chest;
}

Player * GameFactory::createPlayer(glm::vec3 position){
    Player * player = new Player(position);
    player->setBehaviour(new KeysBehaviour( player ));
    player->setCollider(new Collider(player));
    return player;
}

EndCube * GameFactory::createEnd(glm::vec3 position){
    EndCube * ec = new EndCube(position);
    ec->setCollider(new Collider(ec, 100));
    return ec;
}

Room * GameFactory::createRoom(glm::vec3 startPosition, glm::vec3 endPosition, glm::vec3 lichtPositie, glm::vec3 lichtPositie2, std::string muurTexture, std::string vloerTexture, std::string helloRoom){
    Room * room = new Room(startPosition, endPosition, lichtPositie, lichtPositie2, muurTexture, vloerTexture, helloRoom);
    return room;
}
