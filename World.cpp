#include <cassert>

#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"

World::World( std::string aName )
{
	//ctorc
	name = aName;
	rooms = new std::vector<Room *>();
	player = NULL;
}

World::~World()
{
	//dtor
}

void World::update( float step )
{
    //Alleen actieve ruimte updaten?
    activeRoom->update(step);
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

void World::add(Player * player){
    assert(this->player == NULL);
    this->player = player;
    add((GameObject*) player);
}

void World::add(GameObject * object){
    assert(rooms->size() != 0);
    for(std::vector<Room*>::iterator vi = rooms->begin(); vi!= rooms->end(); ++vi){
        Room * i = *vi;
        glm::vec3 start = i->getLocation();
        glm::vec3 end = i->getEndPosition();
        glm::vec3 objectLocation = object->getLocation();

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
    if(rooms->size() == 1){
        setActive(room);
    }
}

void World::setActive(Room * room){
    //TODO check ruimte in tuimtes?
    activeRoom = room;
}

void World::accept(Visitor * visitor){
    visitor->visit(this);
    activeRoom->accept(visitor);
}

