#ifndef KEYSBEHAVIOUR_H
#define KEYSBEHAVIOUR_H

#include "../Behaviour.hpp"
#include "../Player.hpp"
#include "../Chest.hpp"
#include "../Door.hpp"
#include "../World.hpp"
#include "../Time.hpp"
#include <SFML/Audio.hpp>


class KeysBehaviour : public Behaviour
{
	public:
		KeysBehaviour( Player * aParent );
		virtual ~KeysBehaviour();

		virtual void update( float step );
		virtual void onCollision(GameObject * otherGameObject);
    private:
        bool enterDown;
        bool doorHit;
        sf::SoundBuffer * bufferChest;
        sf::Sound * soundChest;
};

#endif // KEYSBEHAVIOUR_H
