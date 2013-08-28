#ifndef GAMEFACTORY_H
#define GAMEFACTORY_H

#include "Mesh.hpp"
#include "Game.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Behaviours/KeysBehaviour.hpp"
#include "Behaviours/RotatingBehaviour.hpp"
#include "Behaviours/BulletBehaviour.hpp"
#include "TwoStepCollider.h"
#include "MeshCollider.hpp"
#include <string>
#include "Texture.hpp"
#include "Collider.hpp"
#include "Asteroid.hpp"
#include "Bullet.hpp"
class Player;
class GameFactory
{
    public:
        GameFactory();
        virtual ~GameFactory();
        Player * createPlayer(glm::vec3 position, World * world);
        Room * createRoom(glm::vec3 startPosition, glm::vec3 endPosition, glm::vec3 lichtPositie, glm::vec3 lichtPositie2, std::string muurTexture, std::string vloerTexture, std::string helloRoom);
        Asteroid * createAsteroid(glm::vec3 position, glm::vec3 velocity, float size, World * world);
        Bullet * createBullet(glm::mat4 transform, glm::vec3 velocity, World * world);
        Camera * createCamera(glm::vec3 position);

    protected:
    private:
        Mesh* createMesh(std::string model, glm::vec3 scale = glm::vec3(1.0f,1.0f,1.0f));
        Texture* createTexture(std::string texture);
        std::map<std::string, Texture*> textures;
        std::map<std::string, Mesh*> meshes;
};

#endif // GAMEFACTORY_H
