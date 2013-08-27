#ifndef WORLD_H
#define WORLD_H

#include "Time.hpp"
#include "GameObject.hpp"
#include "Room.hpp"
#include "Door.hpp"
#include "EndCube.hpp"
#include "Picker.hpp"
#include "Asteroid.hpp"
#include <string>

class Camera;
class Light;
class Door;
class Player;
class Asteroid;

class World
{
	private:
        std::string name;
        Room * activeRoom;
        std::vector< Room * >* rooms;
        Player * player;
        Camera * camera;
        Picker * picker;
        Asteroid * asteroid;
        int asteroidcount;
	public:
		World( std::string aName = NULL );
		void add(GameObject * object);
		void add(Door * door);
		void add(Player * player);
		void add(Camera * camera);
		void add(Picker * picker);
		GameObject * pick(glm::vec2 mouseCoords);
		void remove(GameObject * gameObject);
		void addRoom(Room * room);
		void setActive(Room * room);
		Room * getActiveRoom();
		Player * getPlayer();
		Asteroid * getAsteroid();
		Camera * getCamera();
		int getAsteroidNumber();

		virtual ~World();

		void update( float step );
		bool checkCollisions();

		virtual void accept(Visitor * visitor);

};

#endif // WORLD_H
