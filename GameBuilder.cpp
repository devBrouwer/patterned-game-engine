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
    actions->push_back("door");
    actions->push_back("chest");
    actions->push_back("cube");
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
                        else if(*it == "door"){
                            if(!buildDoor(line, world))
                                return 0;
                        }
                        else if(*it == "chest"){
                            if(!buildChest(line, world))
                                return 0;
                        }
                        else if(*it == "cube"){
                            if(!buildCube(line, world))
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

bool GameBuilder::buildChest(std::string line, World* world){
    //chest x,y(,z) sleutel

    std::vector<std::string> words = getWords(line.substr(6));
    if(words.size() != 2){
        std::cout << "ERROR CHEST: " << line << std::endl;
        return false;
    }
    std::string positie = words[0];
    std::string sleutel = words[1];

    std::vector<std::string> coords = getWords(positie, ',');
    if(coords.size() < 2 || coords.size() > 3){
        std::cout << "ERROR CHEST coords: " << line << std::endl;
        return false;
    }
    std::string coordX = coords[0];
    std::string coordY = coords[1];
    std::string coordZ = "0";
    if(coords.size() == 3){
        coordZ = coords[2];
    }

    std::cout << "chest:" << std::endl;
    std::cout << "\tX: " << coordX <<  std::endl;
    std::cout << "\tY: " << coordY <<  std::endl;
    std::cout << "\tZ: " << coordZ <<  std::endl;
    std::cout << "\tkey: " << sleutel << std::endl;

    return true;
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

bool GameBuilder::buildCube(std::string line, World* world){
    //cube positie grootte texture
     std::vector<std::string> words = getWords(line.substr(5));
    if(words.size() != 3){
        std::cout << "ERROR CUBE: " << line << std::endl;
        return false;
    }
    return true;
}

bool GameBuilder::buildDoor(std::string line, World* world){
    //door positie sleutel
    std::vector<std::string> words = getWords(line.substr(5));
    if(words.size() != 2){
        std::cout << "ERROR DOOR: " << line << std::endl;
        return false;
    }
    return true;
}

bool GameBuilder::buildRoom(std::string line, World* world){
    //room start eind lichtpositie muurtexture vloertexture
    std::vector<std::string> words = getWords(line.substr(5));
    if(words.size() != 5){
        std::cout << "ERROR ROOM: " << line << std::endl;
        return false;
    }
    return true;
}

bool GameBuilder::buildStart(std::string line, World* world){
    //start x,y(,z)
    std::vector<std::string> words = getWords(line.substr(6));
    if(words.size() != 1){
        std::cout << "ERROR START: " << line << std::endl;
        return false;
    }

    std::vector<std::string> coords = getWords(words[0], ',');
    if(coords.size() < 2 || coords.size() > 3){
        std::cout << "ERROR START coords: " << line << std::endl;
        return false;
    }
    std::string coordX = coords[0];
    std::string coordY = coords[1];
    std::string coordZ = "0";
    if(coords.size() == 3){
        coordZ = coords[2];
    }
    std::cout << "start:" << std::endl;
    std::cout << "\tX: " << coordX <<  std::endl;
    std::cout << "\tY: " << coordY <<  std::endl;
    std::cout << "\tZ: " << coordZ <<  std::endl;

    return true;
}

GameBuilder::~GameBuilder()
{
    //dtor
}
