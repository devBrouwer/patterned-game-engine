#include <cassert>

#include "Time.hpp"
#include "FPS.hpp"

#include "Hud.hpp"
#include "Renderer.hpp"
#include "ShaderProgram.hpp"
#include "Game.hpp"
#include "World.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"
#include "Behaviours/KeysBehaviour.hpp"
#include "Behaviours/WASDBehaviour.hpp"
#include "Behaviours/RotatingBehaviour.hpp"
#include "Collider.hpp"
#include "RenderVisitor.hpp"
#include "GameBuilder.hpp"
#include "Picker.hpp"


Game::Game()
:	window(NULL), hud(NULL), renderer(NULL), world(NULL)
{
	window = new sf::RenderWindow( sf::VideoMode( 800, 600 ), "Saxion Game" ); // get a window
	std::cout << "Init Glew" << glewInit() << std::endl;

	//window->setVerticalSyncEnabled( true ); // sync with monitor ->60 hz approx
	renderer = new Renderer( window );
	renderVisitor = new RenderVisitor(renderer);

}

Game::~Game()
{
	//dtor
}

void Game::build()
{
    GameBuilder * builder = new GameBuilder(window);
    world = builder->readFile("level.txt");
    Player * player = world->getPlayer();
    //player->rotate(180.0, glm::vec3(0.0,1.0,0.0));
    //player->pushMessage("Welkom!\nBewegen doe je met de pijltjestoetsen.\nJe zit opgesloten in deze ruimte.\nDe sleutel zit verstopt in een kist.\nVindt de kist.\nGebruik de sleutel om de deur te openen.\nDruk op ENTER om door te gaan.");
    hud = new Hud( window, player );
	renderer->use(  new ShaderProgram( "shaders/default.vs", "shaders/default.fs" ) );
	Picker * picker = new Picker(world->getCamera());
	world->add(picker);
	//for ( int y = 0; y <= 600; y+=30 ) { // check hit object for a raster of rays
	//	for ( int x = 0; x < 800; x+=30 ) {
	//		picker.pick( glm::vec2( x, y ) ); // calculate ray through mouse position from cams eye
	//		bool hit = picker.hits( glm::vec3( 0.2f, -0.2, -0.5f ), 0.5f ); // detect an object is hit
	//		std::cout << hit;
	//		//std::cout << "hoi";
	//	}
	//	std::cout << std::endl;
	//}
}

void Game::run()
{
	running = true;
	while ( running ) {
		Time::update();
		FPS::update();
		control();
		if ( running ) { // control may have changed running;
//            step = Time::step();
			update( Time::step() );
			draw();
		}
	}
}

void Game::pause(){
    running = false;
}

void Game::stop()
{
    window->close();
    running = false;
}

// private functions

void Game::control()
{
	sf::Event event;
	while( window->pollEvent( event ) ) {
		if ( event.type == sf::Event::Closed ) {
			window->close();
			running = false; // running = false;
		}
	}
}

void Game::update( float step )
{
	assert( world != NULL );
	world->update( step );
	checkCollisions();
}

void Game::draw()
{
	assert( window != NULL );
	assert( renderVisitor != NULL );
	assert( world != NULL );

    world->accept(renderVisitor);

	window->pushGLStates();
	hud->draw();
	window->popGLStates();
	window->display();
}


bool Game::checkCollisions()
{
	return world->checkCollisions();
}
