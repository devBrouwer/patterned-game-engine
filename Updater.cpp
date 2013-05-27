#include "Updater.hpp"

Updater::Updater()
{
    //ctor
}

Updater::~Updater()
{
    //dtor
}

void Updater::visit( World* world )
{
    //do nothing
}

void Updater::visit( Camera* camera )
{
    //do nothing
}

void Updater::visit( Light* light )
{
    //do nothing
}

void Updater::visit( GameObject* gameobject )
{
    //do nothing
}

void Updater::visit( Mesh* mesh )
{
    //do nothing
}

void Updater::visit( Behaviour* behaviour, float step )
{
    behaviour->update(step);
}

void Updater::visit( Collider* collider )
{
    //do nothing
}
