#include "KeysBehaviour.hpp"

KeysBehaviour::KeysBehaviour( Player * aParent, Camera * camera , sf::RenderWindow * window )
:	Behaviour( aParent ), doorHit(false), camera(camera), player(aParent), window(window)
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

    bufferEnd = new sf::SoundBuffer();
    if (!bufferEnd->loadFromFile("applause.wav"))
        std::cout << "ERROR applause.wav" << std::endl;
    soundEnd = new sf::Sound();
    soundEnd->setBuffer(*bufferEnd);
    soundEnd->setLoop(false);
    rotation = 0.0;
    //camera->translate(glm::vec3(0.0f,5.0f,0.0f));
}

KeysBehaviour::~KeysBehaviour()
{
}

void KeysBehaviour::update( float step )
{

	float speed = 0.0f; //default if no keys
	float rotationSpeed = 0.0f;
//	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up )) {
//        parent->rotate( step * 50, glm::vec3( 1.0f, 0.0f, 0.0f ) );
//		//transformation =  glm::translate( transformation, glm::vec3(0.0f, 0.0f, -10.0f*step ) );
//	}
//	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Down )) {
//        parent->rotate( -step * 50, glm::vec3( 1.0f, 0.0f, 0.0f ) );
//		//transformation =  glm::translate( transformation, glm::vec3(0.0f, 0.0f, 10.0f*step ) );
//	}
//	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Right )) {
//		rotationSpeed = -135.0f;
//		//transformation = glm::rotate( transformation, -135*step, glm::vec3(0.0f, 1.0f, 0.0f ) );
//	}
//	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Left )) {
//		rotationSpeed = +135.0f;
//		//transformation = glm::rotate( transformation, 135*step, glm::vec3(0.0f, 1.0f, 0.0f ) );
//	}
    if( sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        if(mouseDown){
            //do nothing
        }
        else{
            mouseDown = true;
            //glm::vec2 mousePosition = glm::vec2( sf::Mouse::getPosition( *window ).x, sf::Mouse::getPosition( *window ).y );
            player->pick( glm::vec2( sf::Mouse::getPosition( *window ).x, sf::Mouse::getPosition( *window ).y ) );
        }
    }
    else{
        mouseDown = false;
    }

	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::W )) {
        //parent->rotate( step * 20, glm::vec3( 1.0f, 0.0f, 0.0f ) );
		speed = -10.0f;
	}
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A )) {
		//parent->translate( glm::vec3( -step * 5, 0.0f, 0.0f ) );
		rotationSpeed = +135.0f;
	}
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::S )) {
		speed = 10.0f;
	}
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D )) {
		//parent->translate( glm::vec3( step * 5, 0.0f, 0.0f ) );
		rotationSpeed = -135.0f;
	}
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Space )) {
		if(spaceDown){
            //do nothing
		}
		else{
            spaceDown = true;
            player->shoot();
		}
	}
	else{
       spaceDown = false;
    }
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Return )){
        if(enterDown){
            //do nothing
        }
        else{
            enterDown = true;
            //std::cout << "popping" << std::endl;
            player->popMessage();
        }
	}
	else{
        enterDown = false;
	}
    parent->rotate( rotationSpeed*step, glm::vec3(0.0f, 1.0f, 0.0f ) );
	parent->translate( glm::vec3(0.0f, 0.0f, speed*step ) );

	if(rotationSpeed != 0){
        rotation = fmodf(rotation + (rotationSpeed*step), 360.0f);
        //std::cout << "ROTATION: " << rotation << std::endl;
    }
	float camerax = 15.0f * sin((rotation) * M_PI / 180) + parent->getLocation().x;
    float cameraz = 15.0f * cos((rotation) * M_PI / 180) + parent->getLocation().z;
    camera->setPosition(glm::vec3(camerax, 6.0f, cameraz));


    //dit loopt om een of andere reden heel hoog te worden...
    //float cameraChangeX = camerax - camera->getLocation().x;
    //float cameraChangeZ = cameraz - camera->getLocation().z;

    //std::cout << "x,z: " << camerax << "," << cameraz << std::endl;
    //std::cout << "x,z: " << cameraChangeX << "," << cameraChangeZ << std::endl;


    //if(rotationSpeed != 0.0f || speed != 0.0f){
    camera->rotate(rotationSpeed*step, glm::vec3(0.0f,1.0f, 0.0f));
        //camera->translate( glm::vec3(cameraChangeX, 0.0f, cameraChangeZ));
    //}


//	transformation = glm::translate( transformation, glm::vec3(0.0f, 0.0f, speed*step ) );
//	transformation = glm::rotate( transformation, rotationSpeed*step, glm::vec3(0.0f, 1.0f, 0.0f ) );

}

void KeysBehaviour::onCollision(GameObject * aGameObject){
    //std::cout << "dit wordt aangeroepen!" << std::endl;
//    Chest * chest = dynamic_cast<Chest*>(aGameObject);
//    if(chest!= NULL){
//        doorHit = false;
//        //it's a chest!
//        //std::cout << "HItting chest!" << std::endl;
//        if(!chest->getOpened()){
//            chest->open();
//            std::string key = chest->getKey();
//            ((Player*)parent)->pushMessage("Deze kist geeft je een sleutel! (" + key + ")" );
//            ((Player*)parent)->setKey(key);
//            soundChest->play();
//        }
//        //std::cout << "Player hits chest" << std::endl;
//
//    }
//    else {
//        Door * door = dynamic_cast<Door*>(aGameObject);
//        if(door!= NULL){
//            if(doorHit){
//                // al iets mee gedaan...
//            }
//            else{
//                doorHit = true;
//                if(door->isOpened()){
//                    ((Player*)parent)->pushMessage("Je kunt niet terug...");
//                }
//                else if(((Player*)parent)->hasKey(door->getKey())){
//                    ((Player*)parent)->pushMessage("Deur geopend met sleutel: " + door->getKey() );
//                    door->setOpened(true);
//                    soundDoor->play();
//                    ((Player*)parent)->setKey(""); //sleutel is maar 1x te gebruiken
//                    Room * room1 = door->getRoom1();
//                    Room * room2 = door->getRoom2();
//                    Room * room3 = door->getRoom3();
//                    if(door->getWorld()->getActiveRoom() == room1){
//                        //switch to room2
//                        door->getWorld()->setActive(room2);
//                        room2->add((Player*)parent);
//                        //room1->remove((Player*)parent);
//                    } else if(door->getWorld()->getActiveRoom() == room2){
//                        door->getWorld()->setActive(room3);
//                        room3->add((Player*)parent);
//                    } else{
//                        door->getWorld()->setActive(room1);
//                        room1->add((Player*)parent);
//                        //room2->remove((Player*)parent);
//                    }
//                }
//                else {
//                    ((Player*)parent)->pushMessage("Je hebt deze sleutel nodig: " + door->getKey() );
//                }
//                //std::cout << "Player hits door" << std::endl;
//            }
//        }
//        else{
//            doorHit = false;
//            EndCube * ec = dynamic_cast<EndCube*>(aGameObject);
//            if(ec != NULL && ((Player*)parent)->getEndTime()==0){
//                ((Player*)parent)->setEndTime(Time::now());
//                soundEnd->play();
//                //((Player*)parent)->pushMessage("The END!");
//                //std::cout << "Nu moet het stoppen!" << std::endl;
//            }
//        }
//    }


}
