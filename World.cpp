#include <cassert>

#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Player.hpp"

World::World( std::string aName )
{
	//ctorc
	name = aName;
	rooms = new std::vector<Room *>();
	player = NULL;
	camera = NULL;
	picker = NULL;
//	asteroid = NULL;
    asteroidcount = 0;
}

World::~World()
{
	//dtor
}

int World::getAsteroidNumber()
{
    return asteroidcount;
}

void World::update( float step )
{
    //Alleen actieve ruimte updaten?
    activeRoom->update(step);
    activeRoom->removeThings();
//	//camera->update( step );
//	GameObject::update( step );
}

bool World::checkCollisions()
{
    return activeRoom->checkCollisions();
}

Player * World::getPlayer(){
    return player;
}

Asteroid * World::getAsteroid(){
    return asteroid;
}

Camera * World::getCamera(){
    return camera;
}

void World::add(Player * player){
    assert(this->player == NULL);
    this->player = player;
    for(std::vector<Room*>::iterator vi = rooms->begin(); vi!= rooms->end(); ++vi){
        Room * i = *vi;
        glm::vec3 start = i->getLocation();
        glm::vec3 end = i->getEndPosition();
        glm::vec3 objectLocation = player->getLocation();

        if(objectLocation.x >= start.x && objectLocation.x <= end.x && objectLocation.z >= start.z && objectLocation.z <= end.z){
            i->add(player);
            setActive(i);
            break;
        }
    }
}

void World::add(Camera * camera){
    assert(this->camera == NULL);
    this->camera = camera;
    add((GameObject *)camera);
}

void World::add(Picker * picker){
    assert(this->picker == NULL);
    this->picker = picker;
}

GameObject * World::pick(glm::vec2 mouseCoords){
    return activeRoom->pick(mouseCoords, picker);
}



void World::add(GameObject * object){
    assert(rooms->size() != 0);

    for(std::vector<Room*>::iterator vi = rooms->begin(); vi!= rooms->end(); ++vi){
        Room * i = *vi;
        glm::vec3 start = i->getLocation();
        glm::vec3 end = i->getEndPosition();
        glm::vec3 objectLocation = object->getLocation();

        if(object->getName() == "Asteroid"){
            std::cout << "Een asteroide is aangemaakt" << std::endl;
            asteroidcount++;
            std::cout << asteroidcount << std::endl;
        }

        if(objectLocation.x >= start.x && objectLocation.x <= end.x && objectLocation.z >= start.z && objectLocation.z <= end.z){
            i->add(object);
            break;
        }
    }
    //uitrekenen aan welke room het toegevoegd moet worden
    //toevoegen aan die ruimte
}

Room * World::getActiveRoom(){
    return activeRoom;
}

void World::remove(GameObject * gameObject){
    activeRoom->remove(gameObject);
    if(gameObject->getName() == "Asteroid"){
        std::cout << "Een asteroide is vernietigd" << std::endl;
        if(asteroidcount != 1){
        asteroidcount--;
        std::cout << asteroidcount << std::endl;
        }else{
            asteroidcount--;
            std::cout << "No more asteroids!" << std::endl;
            std::cout << asteroidcount << std::endl;
            player->pushMessage("Je hebt alle asteroiden kapot gemaakt!");
            player->setEndTime(Time::now());
        }
    }
}

void World::add(Door * door){
    int addedTo = 0;
    for(std::vector<Room*>::iterator vi = rooms->begin(); vi!= rooms->end(); ++vi){
        Room * i = *vi;
        glm::vec3 start = i->getLocation();
        glm::vec3 end = i->getEndPosition();
        glm::vec3 objectLocation = door->getLocation();

        if(objectLocation.x >= start.x && objectLocation.x <= end.x && objectLocation.z >= start.z && objectLocation.z <= end.z){
            i->add(door);
            ++addedTo;
            if(addedTo == 1)
                door->setRoom1(i);
            if(addedTo == 2){
                door->setRoom2(i);
                break;
                std::cout << "Deur aan 2 Ruimtes toegevoegd :)" << std::endl;
            }
        }
    }
    if(addedTo != 2){
        std::cout << "ERROR: deur verbindt geen ruimtes!" << std::endl;
    }

    //uitrekenen aan welke 2 rooms het toegevoegd moet worden

    //toevoegen aan die ruimtes
}

void World::addRoom(Room * room){
    rooms->push_back(room);
    //onderstaande wordt nu in add Player gedaan
    //if(rooms->size() == 1){
    //    setActive(room);
    //}
}

void World::setActive(Room * room){
    //TODO check ruimte in tuimtes?
    activeRoom = room;
    if(player != 0 && !room->getHelloRoom().empty()){
        player->pushMessage(room->getHelloRoom());
    }
}

void World::accept(Visitor * visitor){
    visitor->visit(this);
    activeRoom->accept(visitor);
}

