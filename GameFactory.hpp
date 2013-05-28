#ifndef GAMEFACTORY_H
#define GAMEFACTORY_H

#include "Mesh.hpp"
#include "Game.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Behaviours/KeysBehaviour.hpp"
#include <string>

class GameFactory
{
    public:
        GameFactory();
        virtual ~GameFactory();
        Mesh* createMesh();
        World* createWorld();

        Light* createLight(glm::vec3 position);
        Camera* createCamera(glm::vec3 position);
        Room* createRoom(glm::vec3 startPosition, glm::vec3 endPosition, glm::vec3 lichtPositie, std::string muurTexture, std::string vloerTexture );
        GameObject* createKubus(glm::vec3 position, int size, std::string texture);
        GameObject* createDeur(glm::vec3 position, glm::vec3 chestPosition, std::string texture);

    protected:
    private:
};

#endif // GAMEFACTORY_H
