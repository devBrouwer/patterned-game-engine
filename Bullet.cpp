#include "Bullet.hpp"
#include "World.hpp"

Bullet::Bullet(glm::mat4 aTransform, glm::vec3 velocity, World * world) : GameObject("Bullet", aTransform), velocity(velocity), world(world)
{
    //ctor
}

Bullet::~Bullet()
{
    //dtor
}

glm::vec3 Bullet::getVelocity(){
    return velocity;
}

void Bullet::setVelocity(glm::vec3 aVelocity){
    velocity = aVelocity;
}

void Bullet::removeMe(){
    std::cout << "Request bullet removal" << std::endl;
    world->remove(this);
}
