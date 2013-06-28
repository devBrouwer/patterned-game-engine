#include "KeysBehaviour.hpp"
#include <sfml/window.hpp>

#include "../GameObject.hpp"

KeysBehaviour::KeysBehaviour( Player * aParent )
:	Behaviour( (GameObject*)aParent ), doorHit(false)
{
    bufferChest = new sf::SoundBuffer();
    if (!bufferChest->loadFromFile("chest.wav"))
        std::cout << "ERROR chest.wav" << std::endl;
    soundChest = new sf::Sound();
    soundChest->setBuffer(*bufferChest);
    soundChest->setLoop(false);

    bufferDoor = new sf::SoundBuffer();
    if (!bufferDoor->loadFromFile("door.wav"))
        std::cout << "ERROR door.wav" << std::endl;
    soundDoor = new sf::Sound();
    soundDoor->setBuffer(*bufferDoor);
    soundDoor->setLoop(false);
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
        //std::cout << "HItting chest!" << std::endl;
        if(!chest->getOpened()){
            chest->open();
            std::string key = chest->getKey();
            ((Player*)parent)->pushMessage("Deze kist geeft je een sleutel! (" + key + ")" );
            ((Player*)parent)->setKey(key);
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
                if(door->isOpened()){
                    ((Player*)parent)->pushMessage("Je kunt niet terug...");
                }
                else if(((Player*)parent)->hasKey(door->getKey())){
                    ((Player*)parent)->pushMessage("Deur geopend met sleutel: " + door->getKey() );
                    door->setOpened(true);
                    soundDoor->play();
                    ((Player*)parent)->setKey(""); //sleutel is maar 1x te gebruiken
                    Room * room1 = door->getRoom1();
                    Room * room2 = door->getRoom2();
                    Room * room3 = door->getRoom3();
                    if(door->getWorld()->getActiveRoom() == room1){
                        //switch to room2
                        door->getWorld()->setActive(room2);
                        room2->add((Player*)parent);
                        //room1->remove((Player*)parent);
                    } else if(door->getWorld()->getActiveRoom() == room2){
                        door->getWorld()->setActive(room3);
                        room3->add((Player*)parent);
                    } else{
                        door->getWorld()->setActive(room1);
                        room1->add((Player*)parent);
                        //room2->remove((Player*)parent);
                    }
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
