#include <cassert>

#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"

World::World( std::string aName )
{
	//ctorc
	name = aName;
	rooms = new std::vector<Room *>();
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

void World::add(GameObject * object){
    for(std::vector<Room*>::iterator vi = rooms->begin(); vi!= rooms->end(); ++vi){
        Room * i = *vi;
        glm::vec3 start = i->getLocation();
        glm::vec3 end = i->getEndPosition();
        glm::vec3 objectLocation = object->getLocation();

        if(objectLocation.x >= start.x && objectLocation.x <= end.x && objectLocation.y >= start.y && objectLocation.y <= end.y){
            i->add(object);
            break;
        }
    }


    //uitrekenen aan welke room het toegevoegd moet worden

    //toevoegen aan die ruimte
}

void World::add(Door * door){
    int addedTo = 0;
    for(std::vector<Room*>::iterator vi = rooms->begin(); vi!= rooms->end(); ++vi){
        Room * i = *vi;
        glm::vec3 start = i->getLocation();
        glm::vec3 end = i->getEndPosition();
        glm::vec3 objectLocation = door->getLocation();

        if(objectLocation.x >= start.x && objectLocation.x <= end.x && objectLocation.y >= start.y && objectLocation.y <= end.y){
            i->add(door);
            ++addedTo;
            if(addedTo == 2)
                break;
        }
    }

    //uitrekenen aan welke 2 rooms het toegevoegd moet worden

    //toevoegen aan die ruimtes
}

void World::addRoom(Room * room){
    rooms->push_back(room);
}

void World::setActive(Room * room){
    //TODO check ruimte in tuimtes?
    activeRoom = room;
}

void World::accept(Visitor * visitor){
    visitor->visit(this);
    activeRoom->accept(visitor);
}

