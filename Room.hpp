#ifndef ROOM_H
#define ROOM_H

#include "GameObject.hpp"
#include "Light.hpp"
#include "Mesh.hpp"
#include "WallCollider.hpp"
#include "Texture.hpp"
#include <vector>
#include "Picker.hpp"

class Room : public GameObject
{
    public:
        Room( glm::vec3 startPosition, glm::vec3 endPosition, glm::vec3 lichtPositie, glm::vec3 lichtPositie2, std::string muurTexture, std::string vloerTexture, std::string helloRoom = "");
        virtual ~Room();
        bool checkCollisions();
        glm::vec3 getEndPosition();
        virtual void add(GameObject * aChild);
        void remove(GameObject * aChild);
        void removeThings();
        std::string getHelloRoom();
        GameObject * pick(glm::vec2 mouseCoords, Picker * picker);
    protected:
    private:
        std::vector< GameObject * >* removeList;
        glm::vec3 endPosition;
        std::string helloRoom;

};

#endif // ROOM_H
