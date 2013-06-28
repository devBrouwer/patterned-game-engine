#include "Player.hpp"

Player::Player(glm::vec3 position) : Camera("Player", position), endTime(0)
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

void Player::setKey(std::string aKey){
    key = aKey;
}

bool Player::hasKey(std::string aKey){
    return key == aKey;
}

std::string Player::getKey(){
    return key;
}

float Player::getEndTime(){
    return endTime;
}

void Player::setEndTime(float time){
    endTime = time;
}
