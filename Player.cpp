#include "Player.hpp"

Player::Player(glm::vec3 position) : Camera("Player", position)
{
    //ctor
}

Player::~Player()
{
    //dtor
}

std::string Player::getNextMessage(){
    if(messages.empty())
        return "";
    else
        return messages.front();
}

void Player::popMessage(){
    if(!messages.empty())
        messages.pop();
}

void Player::pushMessage(std::string message){
    messages.push(message);
}

void Player::addKey(std::string key){
    keys.push_back(key);
}

bool Player::hasKey(std::string key){
    for(std::vector<std::string>::iterator it = keys.begin() ; it != keys.end(); ++it){
        if(key == *it){
            return true;
        }
    }
    return false;
}

std::vector<std::string> Player::getKeys(){
    return keys;
}
