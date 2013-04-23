#ifndef WORLD_H
#define WORLD_H

#include "GameObject.hpp"
#include "Ruimte.hpp"
#include <string>

class Camera;
class Light;

class World
{
	private:
        std::string name;
        Ruimte * actieveRuimte;
        std::vector< Ruimte * >* ruimtes;

	public:
		World( std::string aName = NULL );
		void add(Ruimte * ruimte);
		void setActive(Ruimte * ruimte);

		virtual ~World();

		void update( float step );
		bool checkCollisions();

		virtual void accept(Visitor * visitor);

};

#endif // WORLD_H
