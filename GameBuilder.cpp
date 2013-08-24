#include "GameBuilder.hpp"

#include <iostream>
#include <fstream>
#include <string>

GameBuilder::GameBuilder()
{
    //ctor
    actions = new std::vector<std::string>();
    actions->push_back("start");
    actions->push_back("room");
    actions->push_back("asteroid");
    factory = new GameFactory();
}

World* GameBuilder::readFile(std::string filename){
    std::string line;
    std::ifstream myfile (filename.c_str());
    World* world = new World("World");
    if (myfile.is_open()){
        while ( myfile.good() ){
            //string word << myfile;
            getline (myfile,line);
            if(line.empty()){
                //ignore line
            }
            else if(line.substr(0,1) == "#"){
                //comment ignore
            }
            else{
                //ophakken in woorden
                bool lineProcessed = false;
                for (std::vector<std::string>::iterator it = actions->begin() ; it != actions->end(); ++it){
                    if(line.substr(0,(*it).size()) == *it){
                        lineProcessed = true;
                        std::cout << "MATCH: " << line << std::endl;
                        if(*it == "start"){
                            if(!buildStart(line, world))
                                return 0;
                        }
                        else if(*it == "room"){
                            if(!buildRoom(line, world))
                                return 0;
                        }
                        else if(*it == "asteroid"){
                            if(!buildAsteroid(line, world))
                                return 0;
                        }
                        break;
                    }
                }
                if(!lineProcessed){
                    std::cout << "NO MATCH: " << line << std::endl;
                }
            }
        }
        myfile.close();
        return world;
    }
    else {
        std::cout << "Unable to open file";
        return 0;
    }
}

std::vector<std::string> GameBuilder::getWords(std::string line, char delimiter/*= ' '*/){
    std::vector<std::string> words;
    int i = 0;
    int begin = 0;
    while(i <= line.size()){
        if(line[i] == delimiter || i==line.size() ){
            words.push_back(line.substr(begin, i-begin));
            begin = i+1;
        }
        ++i;
    }
    return words;
}

glm::vec3 GameBuilder::getVec3(std::string coordsString){
    std::vector<std::string> coords = getWords(coordsString, ',');
    if(coords.size() < 2 || coords.size() > 3){
        std::cout << "ERROR making VEC3: " << coordsString << std::endl;
        return glm::vec3(0,0,0);
    }
    //atof converts a c_string to float
    float x = ::atof((coords[0]).c_str());
    float y;
    float z;
    if(coords.size()==3){
        y = ::atof((coords[1]).c_str());
        z = ::atof((coords[2]).c_str());
    }
    else {
        y = 0.0;
        z = atof((coords[1]).c_str());
    }
    return glm::vec3(x,y,z);
}

bool GameBuilder::buildAsteroid(std::string line, World* world){
    //cube positie grootte texture
    std::vector<std::string> words = getWords(line.substr(9));
    if(words.size() != 3){
        std::cout << "ERROR ASTEROID: " << line << std::endl;
        return false;
    }
    glm::vec3 position = getVec3(words[0]);

   glm::vec3 velocity = getVec3(words[1]);
    std::string sizeString = words[2];
    float size = ::atof(sizeString.c_str());

    std::cout << "asteroid:" << std::endl;
    std::cout << "\tposition: " << position << std::endl;
    std::cout << "\tvelocity: " << velocity << std::endl;
    std::cout << "\tsize: " << size << std::endl << std::endl;

    Asteroid * a = factory->createAsteroid(position, velocity, size);
    world->add(a);

    return true;
}

bool GameBuilder::buildRoom(std::string line, World* world){
    //room start eind lichtpositie muurtexture vloertexture
    std::vector<std::string> words = getWords(line.substr(6));
    if(words.size() != 6 && words.size() != 7){
        std::cout << "ERROR ROOM: " << line << std::endl;
        return false;
    }
    glm::vec3 start = getVec3(words[0]);
    glm::vec3 end = getVec3(words[1]);
    glm::vec3 light = getVec3(words[2]);
    glm::vec3 light2 = getVec3(words[3]);
    std::string wallTexture = words[4];
    std::string floorTexture = words[5];
    std::string msg = "";
    if(words.size() == 7){
        msg = words[6];
    }

    std::cout << "room:" << std::endl;
    std::cout << "\t start: " << start << std::endl;
    std::cout << "\t end: " << end << std::endl;
    std::cout << "\t light: " << light << std::endl;
    std::cout << "\t light2: " << light2 << std::endl;
    std::cout << "\t wall: " << wallTexture << std::endl;
    std::cout << "\t floor: " << floorTexture << std::endl << std::endl;
    std::cout << "\t msg: " << msg << std::endl << std::endl;


    Room * room = factory->createRoom(start, end, light, light2, wallTexture, floorTexture, msg);
    world->addRoom(room);

    return true;
}

bool GameBuilder::buildStart(std::string line, World* world){
    //start x,y(,z)
    std::vector<std::string> words = getWords(line.substr(6));
    if(words.size() != 1){
        std::cout << "ERROR START: " << line << std::endl;
        return false;
    }

    glm::vec3 position = getVec3(words[0]);

    std::cout << "start:" << std::endl;
    std::cout << "\tposition: " << position << std::endl <<  std::endl;

    Player * p = factory->createPlayer(position);
    world->add(p);

    return true;
}

GameBuilder::~GameBuilder()
{
    //dtor
}
