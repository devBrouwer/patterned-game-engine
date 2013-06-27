#ifndef PLAYER_H
#define PLAYER_H

#include "Camera.hpp"
#include <queue>


class Player : public Camera
{
    public:
        /** constructor */
        Player(glm::vec3 position);
        /** Default destructor */
        virtual ~Player();
        std::string getNextMessage();
        void popMessage();
        void pushMessage(std::string);
    protected:
    private:
        std::queue<std::string> messages;
};

#endif // PLAYER_H
