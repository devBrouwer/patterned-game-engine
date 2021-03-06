#ifndef GAMEBUILDER_H
#define GAMEBUILDER_H

#include <string>
#include <vector>
#include "World.hpp"
#include "GameFactory.hpp"
#include "Behaviours/CameraBehaviour.hpp"

class GameBuilder
{
    public:
        GameBuilder(sf::RenderWindow * window);
        World* readFile(std::string filename);
        virtual ~GameBuilder();
        bool buildStart(std::string line, World* world);
        bool buildRoom(std::string line, World* world);
        bool buildAsteroid(std::string line, World* world);
    protected:
    private:
        GameFactory * factory;
        std::vector<std::string>* actions;
        std::vector<std::string>  getWords(std::string line, char delimiter = ';');
        glm::vec3 getVec3(std::string coordsString);
        sf::RenderWindow * window;
};

#endif // GAMEBUILDER_H
