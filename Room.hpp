#ifndef ROOM_H
#define ROOM_H

#include "GameObject.hpp"
#include "Light.hpp"

class Room : public GameObject
{
    public:
        Room( glm::vec3 startPosition, glm::vec3 endPosition, glm::vec3 lichtPositie, glm::vec3 lichtPositie2, std::string muurTexture, std::string vloerTexture);
        virtual ~Room();
        bool checkCollisions();
        glm::vec3 getEndPosition();
    protected:
    private:
        Light * light;
        glm::vec3 endPosition;

};

#endif // ROOM_H
