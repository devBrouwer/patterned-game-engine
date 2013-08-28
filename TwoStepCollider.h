#ifndef TWOSTEPCOLLIDER_H
#define TWOSTEPCOLLIDER_H

#include "Collider.hpp"


class TwoStepCollider : public Collider
{
    public:
        /** Default constructor */
        TwoStepCollider(GameObject * aParent, Collider * broad, Collider * narrow);
        /** Default destructor */
        virtual ~TwoStepCollider();
        virtual bool collides(Collider * otherCollider, bool reportCollision=true);
    protected:
    private:
        Collider * broad;
        Collider * narrow;
};

#endif // TWOSTEPCOLLIDER_H
