#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.hpp"
#include <queue>
#include <vector>
#include "Bullet.hpp"

class GameFactory;


class Player : public GameObject
{
    public:
        /** constructor */
        Player(glm::vec3 position, GameFactory * aFactory, World * world, Texture * fireTexture);
        /** Default destructor */
        virtual ~Player();
        std::string getNextMessage();
        void popMessage();
        void die();
        void pushMessage(std::string);
        void setKey(std::string key);
        bool hasKey(std::string key);
        std::string getKey();
        void setEndTime(float);
        float getEndTime();
        void shoot();
        void removeMe();
        void pick(glm::vec2 mouseCoords);
        bool getDead();
    protected:
    private:
        std::queue<std::string> messages;
        std::string key;
        float endTime;
        Texture * fireTexture;
        GameFactory * factory;
        World * world;
        bool dead;
};

#endif // PLAYER_H
