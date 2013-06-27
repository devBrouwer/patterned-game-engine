#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.hpp"


class Player : public GameObject
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
