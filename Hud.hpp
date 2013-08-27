#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include "Time.hpp"
///veranderen naar player
#include "Player.hpp"
#include "World.hpp"
#include "Camera.hpp"

class Hud
{
	private:
		sf::RenderWindow * window;
//		sf::Font font;
//		sf::Texture marvinTex;
//		sf::Sprite marvin;
        Player * player;
        World * world;
        Camera * camera;
	public:
		Hud( sf::RenderWindow * aWindow, Player * aPlayer );
		virtual ~Hud();

		void draw( );
};

#endif // HUD_H
