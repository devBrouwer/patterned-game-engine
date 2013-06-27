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
