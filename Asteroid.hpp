#ifndef ASTEROID_H
#define ASTEROID_H

#include "GameObject.hpp"


class Asteroid : public GameObject
{
    public:
        /** Default constructor */
        Asteroid(glm::vec3 position, glm::vec3 velocity);
        /** Default destructor */
        virtual ~Asteroid();
        glm::vec3 getVelocity();
        void setVelocity(glm::vec3 newVelocity);
    protected:
    private:
        glm::vec3 velocity;
};

#endif // ASTEROID_H
