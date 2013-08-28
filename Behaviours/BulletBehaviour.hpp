#ifndef BULLETBEHAVIOUR_H
#define BULLETBEHAVIOUR_H

#include "../Behaviour.hpp"
#include "../Bullet.hpp"
#include "../GameObject.hpp"
#include "../Player.hpp"


class BulletBehaviour : public Behaviour
{
    public:
        /** Default constructor */
        BulletBehaviour(Bullet * bullet);
        /** Default destructor */
        virtual ~BulletBehaviour();
        virtual void update(float step);
        virtual void onCollision(GameObject * otherGameObject);
    protected:
    private:
        Bullet * bullet;
};

#endif // BULLETBEHAVIOUR_H
