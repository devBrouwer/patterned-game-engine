#include "Player.hpp"
#include "GameFactory.hpp"
#include "World.hpp"

Player::Player(glm::vec3 position, GameFactory * aFactory, World * world) : GameObject("Player", position), endTime(0), factory(aFactory), world(world)
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

void Player::shoot(){
    Bullet * b = factory->createBullet(transform, glm::vec3(0.0f,0.0f,-5.0f), world);
    //kickstart:
    b->translate(glm::vec3(0.0f, 0.0f, -5.0f));
    world->add(b);
}

void Player::pick(glm::vec2 mouseCoords){
    GameObject * underMouse = world->pick(mouseCoords);
    if(underMouse != NULL){
        pushMessage(underMouse->getName() + ": " + glm::to_string(underMouse->getLocation()) );
    }
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

void Player::removeMe(){
    //std::cout << "Request bullet removal" << std::endl;
    world->remove(this);
}
