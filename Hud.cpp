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
	text.setStyle(sf::Text::Regular);
	text.setColor(sf::Color::White);
	text.setPosition( 150,10);

	//char uitleg[] = "";

	sf::Text textUitleg( player->getNextMessage().c_str() );
	//text.setFont(font);
	textUitleg.setCharacterSize(20);
	textUitleg.setStyle(sf::Text::Bold);
	textUitleg.setColor(sf::Color::White);
	textUitleg.setPosition( 200,200);

    char laptime[] = "Pass a checkpoint\n to start...";
    float time = Time::now();
    float current_time = time;
    sprintf( laptime, "Tijdsduur: %2.1f seconden", current_time );
    sf::Text laptext( laptime );
    laptext.setCharacterSize(20);
    laptext.setStyle(sf::Text::Bold);
    laptext.setColor(sf::Color::White);
    laptext.setPosition( 10,570);
    window->draw(laptext);

//    std::string key = player->getKeys();
//	sf::Text textKeys( "Deze kist geeft je een sleutel! (" + key + ")" );
//	//text.setFont(font);
//	textKeys.setCharacterSize(20);
//	textKeys.setStyle(sf::Text::Bold);
//	textKeys.setColor(sf::Color::White);
//	textKeys.setPosition( 500,570);

	// Draw it
	//std::cout << "Drawing text" << std::endl;
	assert ( window != NULL );
//	window->draw( marvin );
	window->draw(textFPS);
	window->draw(text);
	window->draw(textUitleg);
    window->draw(laptext);
//    window->draw(textKeys);

}
