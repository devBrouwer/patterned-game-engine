#include <cassert>

#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"

World::World( std::string aName )
{
	//ctorc
	name = aName;
	ruimtes = new std::vector<Ruimte *>();
}

World::~World()
{
	//dtor
}

void World::update( float step )
{
    //Alleen actieve ruimte updaten?
    actieveRuimte->update(step);
//	//camera->update( step );
//	GameObject::update( step );
}

bool World::checkCollisions()
{
    return actieveRuimte->checkCollisions();
}

void World::add(Ruimte * ruimte){
    ruimtes->push_back(ruimte);
}

void World::setActive(Ruimte * ruimte){
    //TODO check ruimte in tuimtes?
    actieveRuimte = ruimte;
}

void World::accept(Visitor * visitor){
    visitor->visit(this);
    actieveRuimte->accept(visitor);
}

