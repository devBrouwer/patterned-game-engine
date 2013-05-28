#include "GameFactory.hpp"

GameFactory::GameFactory()
{
    //ctor
}

GameFactory::~GameFactory()
{
    //dtor
}

Camera* GameFactory::createCamera(glm::vec3 location){
    Camera* camera = new Camera( "Camera", location );
		camera->setBehaviour( new KeysBehaviour( camera ) );
    return camera;
}

Light* GameFactory::createLight(glm::vec3 location){
    Light* light = new Light( "Light", glm::vec3( 2.0f, 10.0f, 15.0f ) );
    return light;
}

World* GameFactory::createWorld(){
	World* world = new World( "World" );
    return world;
}


