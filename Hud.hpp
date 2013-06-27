#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>

///veranderen naar player
#include "Player.hpp"

class Hud
{
	private:
		sf::RenderWindow * window;
//		sf::Font font;
//		sf::Texture marvinTex;
//		sf::Sprite marvin;
        Player * cam;
	public:
		Hud( sf::RenderWindow * aWindow, Player * aCam );
		virtual ~Hud();

		void draw( );
};

#endif // HUD_H
