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

Game::Game()
:	window(NULL), hud(NULL), renderer(NULL), world(NULL)
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
    GameBuilder * test = new GameBuilder();
    test->readFile("level.txt");
	renderer->use(  new ShaderProgram( "shaders/default.vs", "shaders/default.fs" ) );
	Camera* camera = new Camera( "Camera", glm::vec3( 0, 1, 10 ) );
		camera->setBehaviour( new KeysBehaviour( camera ) );
	world = new World( "World" );
	Room * r1 = new Room(glm::vec3(0.0,0.0,0.0), glm::vec3(10.0,10.0,10.0),  glm::vec3( 2.0f, 10.0f, 15.0f ), "models/bricks.jpg", "models/floor.jpg");
	world->addRoom(r1);
	world->setActive(r1);
		r1->add( camera );
		//de kist waar de sleutel in zit
		GameObject * player = new GameObject("Player", glm::vec3( 0.0, 0.0, 0.0 ));
			player->setMesh( Mesh::load( "models/chest3.obj") );
			player->setColorMap( Texture::load("models/bricks.jpg") );
			player->setCollider( new Collider( player ) );
			r1->add( player  );
        //de vloer van de kamer
		GameObject * floor = new GameObject("Floor", glm::vec3( 0,0,0 ) );
			floor->setMesh( Mesh::load( "models/floor.obj" ) );
			floor->setColorMap( Texture::load( "models/floor.jpg" ) );
			r1->add( floor );
		GameObject * cube = new GameObject("Cube", glm::vec3( 0.0, 0.0, 2.0 ));
			cube->setMesh( Mesh::load( "models/cube.obj") );
			cube->setColorMap( Texture::load("models/bricks.jpg") );
			cube->setCollider( new Collider( cube ) );
			r1->add( cube  );
		GameObject * cube2 = new GameObject("Cube2", glm::vec3( 0.0, 0.0, 4.0 ));
			cube2->setMesh( Mesh::load( "models/cube2.obj") );
			cube2->setColorMap( Texture::load("models/bricks.jpg") );
			cube2->setCollider( new Collider( cube2 ) );
			r1->add( cube2  );

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
