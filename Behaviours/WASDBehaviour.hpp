#ifndef WASDBEHAVIOUR_H
#define WASDBEHAVIOUR_H

#include <SFML/Window.hpp>
#include "../Behaviour.hpp"


class WASDBehaviour : public Behaviour
{
	public:
		WASDBehaviour( GameObject * aParent);
		virtual ~WASDBehaviour();

		virtual void update( float step );
};

#endif // WASDBEHAVIOUR_H
