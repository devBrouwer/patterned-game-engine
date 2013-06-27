#include "KeysBehaviour.hpp"
#include <sfml/window.hpp>

#include "../GameObject.hpp"

KeysBehaviour::KeysBehaviour( Player * aParent )
:	Behaviour( (GameObject*)aParent ), doorHit(false)
{
    bufferChest = new sf::SoundBuffer();
    if (!bufferChest->loadFromFile("engine.wav"))
        std::cout << "ERROR engine.wav" << std::endl;
    soundChest = new sf::Sound();
    soundChest->setBuffer(*bufferChest);
    soundChest->setLoop(false);
}

KeysBehaviour::~KeysBehaviour()
{
}

void KeysBehaviour::update( float step )
{
	float speed = 0.0f; //default if no keys
	float rotationSpeed = 0.0f;
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up )) {
		speed = -10.0f;
		//transformation =  glm::translate( transformation, glm::vec3(0.0f, 0.0f, -10.0f*step ) );
	}
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Down )) {
		speed = 10.0f;
		//transformation =  glm::translate( transformation, glm::vec3(0.0f, 0.0f, 10.0f*step ) );
	}
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Right )) {
		rotationSpeed = -135.0f;
		//transformation = glm::rotate( transformation, -135*step, glm::vec3(0.0f, 1.0f, 0.0f ) );
	}
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Left )) {
		rotationSpeed = +135.0f;
		//transformation = glm::rotate( transformation, 135*step, glm::vec3(0.0f, 1.0f, 0.0f ) );
	}
	if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Return )){
        if(enterDown){
            //do nothing
        }
        else{
            enterDown = true;
            //std::cout << "popping" << std::endl;
            ((Player*)parent)->popMessage();
        }
	}
	else{
        enterDown = false;
	}

	parent->translate( glm::vec3(0.0f, 0.0f, speed*step ) );
	parent->rotate( rotationSpeed*step, glm::vec3(0.0f, 1.0f, 0.0f ) );
//	transformation = glm::translate( transformation, glm::vec3(0.0f, 0.0f, speed*step ) );
//	transformation = glm::rotate( transformation, rotationSpeed*step, glm::vec3(0.0f, 1.0f, 0.0f ) );
}

void KeysBehaviour::onCollision(GameObject * aGameObject){
    //std::cout << "dit wordt aangeroepen!" << std::endl;

    Chest * chest = dynamic_cast<Chest*>(aGameObject);
    if(chest!= NULL){
        doorHit = false;
        //it's a chest!
        if(!chest->getOpened()){
            chest->open();
            std::string key = chest->getKey();
            ((Player*)parent)->pushMessage("Deze kist geeft je een sleutel! (" + key + ")" );
            ((Player*)parent)->addKey(key);
            soundChest->play();
        }
        //std::cout << "Player hits chest" << std::endl;

    }
    else {
        Door * door = dynamic_cast<Door*>(aGameObject);
        if(door!= NULL){
            if(doorHit){
                // al iets mee gedaan...
            }
            else{
                doorHit = true;
                if(((Player*)parent)->hasKey(door->getKey())){
                    ((Player*)parent)->pushMessage("Deur geopend met sleutel: " + door->getKey() );
                }
                else {
                    ((Player*)parent)->pushMessage("Je hebt deze sleutel nodig: " + door->getKey() );
                }
                //std::cout << "Player hits door" << std::endl;
            }
        }
        else{
            doorHit = false;
        }
    }


}
