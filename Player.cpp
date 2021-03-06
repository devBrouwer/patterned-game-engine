#include "Player.hpp"
#include "GameFactory.hpp"
#include "World.hpp"

Player::Player(glm::vec3 position, GameFactory * aFactory, World * world, Texture * fireTexture) : GameObject("Player", position), endTime(0), factory(aFactory), world(world), fireTexture(fireTexture), dead(false)
{
    //ctor
}

Player::~Player()
{
    //dtor
}

bool Player::getDead(){
    return dead;
}

void Player::die(){
    this->colorMap = fireTexture;
    dead = true;
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
    std::cout << "creating NEW BULLET! xD" << std::endl;
    Bullet * b = factory->createBullet(transform, glm::vec3(0.0f,0.0f,-5.0f), world);
    //kickstart:
    b->translate(glm::vec3(0.0f, 0.0f, -5.0f));
    world->add(b);
    std::cout << "NEW BULLET created! xD" << std::endl;
}

void Player::pick(glm::vec2 mouseCoords){
    GameObject * underMouse = world->pick(mouseCoords);
    if(underMouse != NULL){
        std::cout << "je hebt op een asteroide geklikt" << std::endl;
        std::cout << glm::to_string(underMouse->getLocation()) << std::endl;
        pushMessage(underMouse->getName() + " location: " + glm::to_string(underMouse->getLocation()) );
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
    std::cout << "Speler is dood" << std::endl;
}
