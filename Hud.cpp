#include <cassert>
#include <iostream>
#include <cstdio>
#include <GL/glew.h>
#include "FPS.hpp"
#include "Hud.hpp"

Hud::Hud( sf::RenderWindow * aWindow, Player * aPlayer )
:	window( aWindow )
{
	assert ( window != NULL );
	player = aPlayer;

//    if ( marvinTex.loadFromFile("models/marvin.png") ) {
//		marvin.setTexture( marvinTex);
//		marvin.setPosition(150,150);
//    } else {
//		std::cout << "Coulf not load sprite" << std::endl;
//	}
}

Hud::~Hud()
{
	//dtor
}

void Hud::draw()
{
	glDisable( GL_CULL_FACE ); // needed for text, dont know why
	char fps[] = "Test";
	sprintf( fps, "%4d", FPS::getFPS() );
	sf::Text textFPS( fps );
	//text.setFont(font);
	textFPS.setCharacterSize(30);
	textFPS.setStyle(sf::Text::Bold);
	textFPS.setColor(sf::Color::White);
	textFPS.setPosition( 10,10);

	char location[] = "Test";
	sprintf( location, "%3f,%3f,%3f", player->getLocation().x,  player->getLocation().y, player->getLocation().z );
	sf::Text text( location );
	//text.setFont(font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color::White);
	text.setPosition( 100,100);

	//char uitleg[] = "";

	sf::Text textUitleg( player->getNextMessage().c_str() );
	//text.setFont(font);
	textUitleg.setCharacterSize(30);
	textUitleg.setStyle(sf::Text::Bold);
	textUitleg.setColor(sf::Color::White);
	textUitleg.setPosition( 100,500);


	// Draw it
	//std::cout << "Drawing text" << std::endl;
	assert ( window != NULL );
//	window->draw( marvin );
	window->draw(textFPS);
	window->draw(text);
	window->draw(textUitleg);
}
