#ifndef ROOM_H
#define ROOM_H

#include "GameObject.hpp"
#include "Light.hpp"
#include "Mesh.hpp"
#include "RectangularPrismCollider.hpp"
#include "Texture.hpp"

class Room : public GameObject
{
    public:
        Room( glm::vec3 startPosition, glm::vec3 endPosition, glm::vec3 lichtPositie, glm::vec3 lichtPositie2, std::string muurTexture, std::string vloerTexture);
        virtual ~Room();
        bool checkCollisions();
        glm::vec3 getEndPosition();
        virtual void add(GameObject * aChild);
        void remove(GameObject * aChild);
    protected:
    private:
        glm::vec3 endPosition;

};

#endif // ROOM_H
