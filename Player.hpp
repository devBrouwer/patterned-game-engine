#ifndef PLAYER_H
#define PLAYER_H

#include "Camera.hpp"


class Player : public Camera
{
    public:
        /** constructor */
        Player(glm::vec3 position);
        /** Default destructor */
        virtual ~Player();
    protected:
    private:
};

#endif // PLAYER_H
