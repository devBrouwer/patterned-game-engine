#include "Asteroid.hpp"

Asteroid::Asteroid(glm::vec3 position, glm::vec3 velocity, Texture * fireTexture, World * world) : GameObject("Asteroid", position), velocity(velocity), fireTexture(fireTexture), world(world)
{
    //ctor
}

Asteroid::~Asteroid()
{
    //dtor
}

glm::vec3 Asteroid::getVelocity(){
    return velocity;
}

void Asteroid::setVelocity(glm::vec3 newVelocity){
    velocity = newVelocity;
}

void Asteroid::setOnFire(){
    setColorMap(fireTexture);
}

void Asteroid::removeMe(){
    world->remove(this);
}
