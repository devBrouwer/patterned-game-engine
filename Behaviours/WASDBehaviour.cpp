#include <iostream>
#include <cmath>
#include <SFML/Window.hpp>

#include "WASDBehaviour.hpp"
#include "../glm.hpp"
#include "../GameObject.hpp"

WASDBehaviour::WASDBehaviour( GameObject * aParent)
:	Behaviour( aParent )
{
}

WASDBehaviour::~WASDBehaviour()
{
}
void WASDBehaviour::update( float step )
{
    float speed = 0.0f; //default if no keys
	float rotationSpeed = 0.0f;
//	glm::ivec2 windowCenter = glm::ivec2( window->getSize().x/2, window->getSize().y/2 );
//	glm::ivec2 mousePosition = glm::ivec2( sf::Mouse::getPosition( *window ).x, sf::Mouse::getPosition( *window ).y );
//	float turnHorizontal = 1.0f * (mousePosition.x - windowCenter.x) / windowCenter.x;

//	parent->rotate( -50 * step * turnHorizontal, glm::vec3( 0.0f, 1.0f, 0.0f ) ); // rotates 45° per second

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
	parent->translate( glm::vec3(0.0f, 0.0f, speed*step ) );
	parent->rotate( rotationSpeed*step, glm::vec3(0.0f, 1.0f, 0.0f ) );
}
