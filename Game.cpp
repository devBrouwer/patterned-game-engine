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

Game::Game()
:	window(NULL), hud(NULL), renderer(NULL), world(NULL), camera(NULL), light(NULL)
{
	window = new sf::RenderWindow( sf::VideoMode( 800, 600 ), "Saxion Game" ); // get a window
	std::cout << "Init Glew" << glewInit() << std::endl;
	hud = new Hud( window );
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
	renderer->use(  new ShaderProgram( "shaders/default.vs", "shaders/default.fs" ) );
	camera = new Camera( "Camera", glm::vec3( 0, 1, 10 ) );
		camera->setBehaviour( new KeysBehaviour( camera ) );
	light = new Light( "Light", glm::vec3( 2.0f, 10.0f, 15.0f ) );
	Mesh * suzanna = Mesh::load( "models/chest3.obj");
	world = new World( "World" );
	Ruimte * r1 = new Ruimte("Ruimte 1");
	world->add(r1);
	world->setActive(r1);
		r1->add( camera );
		r1->add( light );
		//de kist waar de sleutel in zit
		GameObject * player = new GameObject("Player", glm::vec3( 0.0, 0.0, 0.0 ));
			player->setMesh( suzanna );
			player->setColorMap( Texture::load("models/bricks.jpg") );
			player->setCollider( new Collider( player ) );
			r1->add( player  );
        //de vloer van de kamer
		GameObject * floor = new GameObject("Floor", glm::vec3( 0,0,0 ) );
			floor->setMesh( Mesh::load( "models/floor.obj" ) );
			floor->setColorMap( Texture::load( "models/floor.jpg" ) );
			r1->add( floor );
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

void Game::stop()
{
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
