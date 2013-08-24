#ifndef GAMEBUILDER_H
#define GAMEBUILDER_H

#include <string>
#include <vector>
#include "World.hpp"
#include "GameFactory.hpp"

class GameBuilder
{
    public:
        GameBuilder();
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

};

#endif // GAMEBUILDER_H
