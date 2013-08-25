#ifndef ASTEROID_H
#define ASTEROID_H

#include "GameObject.hpp"
#include "World.hpp"


class Asteroid : public GameObject
{
    public:
        /** Default constructor */
        Asteroid(glm::vec3 position, glm::vec3 velocity, Texture * fireTexture, World * world);
        /** Default destructor */
        virtual ~Asteroid();
        glm::vec3 getVelocity();
        void setVelocity(glm::vec3 newVelocity);
        void setOnFire();
        void removeMe();
    protected:
    private:
        glm::vec3 velocity;
        Texture * fireTexture;
        World * world;
};

#endif // ASTEROID_H
