#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Hud;
class Renderer;
class World;
class Camera;
class Light;
class RenderVisitor;
class Game
{
	private: // data members
		sf::RenderWindow * window;
		Hud * hud;
		Renderer * renderer;
		RenderVisitor * renderVisitor;
		World * world;

		bool running;

	public: // functions
		Game();
		virtual ~Game();

		void build();
		void run();
		void stop();
		void pause();

	private:
		void control();
		void update( float step );
		void draw();
		bool checkCollisions();

};

#endif // GAME_H
