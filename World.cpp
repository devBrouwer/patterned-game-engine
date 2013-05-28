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

void World::add(Room * room){
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

