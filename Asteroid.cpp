#include "Asteroid.hpp"

Asteroid::Asteroid(glm::vec3 position, glm::vec3 velocity) : GameObject("Asteroid", position), velocity(velocity)
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
