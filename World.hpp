#ifndef WORLD_H
#define WORLD_H

#include "GameObject.hpp"
#include "Room.hpp"
#include <string>

class Camera;
class Light;

class World
{
	private:
        std::string name;
        Room * activeRoom;
        std::vector< Room * >* rooms;

	public:
		World( std::string aName = NULL );
		void add(Room * room);
		void setActive(Room * room);

		virtual ~World();

		void update( float step );
		bool checkCollisions();

		virtual void accept(Visitor * visitor);

};

#endif // WORLD_H
