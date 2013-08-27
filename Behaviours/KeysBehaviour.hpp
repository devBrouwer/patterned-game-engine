#ifndef KEYSBEHAVIOUR_H
#define KEYSBEHAVIOUR_H

#include "../Behaviour.hpp"
#include "../Player.hpp"
#include "../Chest.hpp"
#include "../Door.hpp"
#include "../World.hpp"
#include "../Time.hpp"
#include "../EndCube.hpp"
#include "../Camera.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class KeysBehaviour : public Behaviour
{
	public:
		KeysBehaviour( Player * aParent , Camera * camera, sf::RenderWindow * window);
		virtual ~KeysBehaviour();

		virtual void update( float step );
		virtual void onCollision(GameObject * otherGameObject);
    private:
        bool enterDown;
        bool spaceDown;
        bool doorHit;
        bool mouseDown;
        sf::SoundBuffer * bufferChest;
        sf::Sound * soundChest;
        sf::SoundBuffer * bufferDoor;
        sf::Sound * soundDoor;
        sf::SoundBuffer * bufferEnd;
        sf::Sound * soundEnd;
        sf::RenderWindow * window;

        float rotation;
        Camera * camera;
        Player * player;
};

#endif // KEYSBEHAVIOUR_H
