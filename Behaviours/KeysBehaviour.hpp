#ifndef KEYSBEHAVIOUR_H
#define KEYSBEHAVIOUR_H

#include "../Behaviour.hpp"
#include "../Player.hpp"


class KeysBehaviour : public Behaviour
{
	public:
		KeysBehaviour( Player * aParent );
		virtual ~KeysBehaviour();

		virtual void update( float step );
    private:
        bool enterDown;
};

#endif // KEYSBEHAVIOUR_H
