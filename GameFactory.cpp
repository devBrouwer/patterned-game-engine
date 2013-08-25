#include "GameFactory.hpp"

GameFactory::GameFactory()
{
    //ctor
}

GameFactory::~GameFactory()
{
    //dtor
}

Mesh* GameFactory::createMesh(std::string model, glm::vec3 scale){
    std::string modelSize = model + glm::to_string(scale);
    if(meshes.find(modelSize) != meshes.end()){
        return meshes.find(modelSize)->second;
    }
    else{
        Mesh* mesh = Mesh::load( model.c_str(), scale);
        meshes.insert( std::pair<std::string,Mesh*>(modelSize, mesh));
        return mesh;
    }
}

Texture* GameFactory::createTexture(std::string texture){
    if(textures.find(texture) != textures.end()){
        return textures.find(texture)->second;
    }
    else{
        Texture* tex = Texture::load( texture.c_str());
        textures.insert( std::pair<std::string,Texture*>(texture, tex));
        return tex;
    }
}

Asteroid* GameFactory::createAsteroid(glm::vec3 position, glm::vec3 velocity, float size){
    Asteroid * asteroid = new Asteroid(position, velocity, createTexture("models/fire.jpg"));
        asteroid->setMesh( createMesh( "models/sphere.obj", glm::vec3(size, size, size)) );
        asteroid->setBehaviour(new RotatingBehaviour( asteroid ));
        asteroid->setColorMap( createTexture("models/asteroid.jpg") );
        asteroid->setCollider( new Collider( asteroid, size ) );
    return asteroid;
}

Player * GameFactory::createPlayer(glm::vec3 position){
    Player * player = new Player(position);
    player->setMesh(createMesh( "models/spaceship.obj"));
    player->setBehaviour(new KeysBehaviour( player ));
    player->setCollider(new Collider(player));
    return player;
}

Room * GameFactory::createRoom(glm::vec3 startPosition, glm::vec3 endPosition, glm::vec3 lichtPositie, glm::vec3 lichtPositie2, std::string muurTexture, std::string vloerTexture, std::string helloRoom){
    Room * room = new Room(startPosition, endPosition, lichtPositie, lichtPositie2, muurTexture, vloerTexture, helloRoom);
    return room;
}
