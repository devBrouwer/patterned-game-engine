#ifndef BULLET_H
#define BULLET_H

#include "GameObject.hpp"


class Bullet : public GameObject
{
    public:
        /** Default constructor */
        Bullet(glm::mat4 transform, glm::vec3 velocity, World * world);
        /** Default destructor */
        virtual ~Bullet();
        glm::vec3 getVelocity();
        void setVelocity(glm::vec3 aVelocity);
        void removeMe();
    protected:
    private:
        glm::vec3 velocity;
        World * world;
};

#endif // BULLET_H
