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
#include "Behaviours/FollowBehaviour.hpp"
#include "Collider.hpp"
#include "RenderVisitor.hpp"
#include "GameBuilder.hpp"


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
    GameBuilder * builder = new GameBuilder();
    world = builder->readFile("level.txt");
    Player * player = world->getPlayer();
    hud = new Hud( window, player );
	renderer->use(  new ShaderProgram( "shaders/default.vs", "shaders/default.fs" ) );
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
