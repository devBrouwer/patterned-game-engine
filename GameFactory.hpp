#ifndef GAMEFACTORY_H
#define GAMEFACTORY_H

#include "Mesh.hpp"
#include "Game.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Behaviours/KeysBehaviour.hpp"
#include <string>
#include "Texture.hpp"
#include "Collider.hpp"
#include "Chest.hpp"
#include "Door.hpp"
#include "Player.hpp"

class GameFactory
{
    public:
        GameFactory();
        virtual ~GameFactory();

        Player * createPlayer(glm::vec3 position);
        Room * createRoom(glm::vec3 startPosition, glm::vec3 endPosition, glm::vec3 lichtPositie, glm::vec3 lichtPositie2, std::string muurTexture, std::string vloerTexture );
        Door * createDoor(glm::vec3 position, std::string texture, std::string key);
        GameObject * createCube(glm::vec3 position, int size, std::string texture);
        Chest * createChest(glm::vec3 position, std::string key);

    protected:
    private:
};

#endif // GAMEFACTORY_H
