#ifndef PLAYER_H
#define PLAYER_H

#include "Camera.hpp"
#include <queue>
#include <vector>


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
        void setKey(std::string key);
        bool hasKey(std::string key);
        std::string getKey();
    protected:
    private:
        std::queue<std::string> messages;
        std::string key;
};

#endif // PLAYER_H
