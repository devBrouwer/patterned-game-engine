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
        void addKey(std::string key);
        bool hasKey(std::string key);
        std::vector<std::string> getKeys();
    protected:
    private:
        std::queue<std::string> messages;
        std::vector<std::string> keys;
};

#endif // PLAYER_H
