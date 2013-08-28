#ifndef TWOSTEPCOLLIDER_H
#define TWOSTEPCOLLIDER_H

#include "Collider.hpp"


class TwoStepCollider : public Collider
{
    public:
        /** Default constructor */
        TwoStepCollider(Collider * broad, Collider * narrow);
        /** Default destructor */
        virtual ~TwoStepCollider();
    protected:
    private:
};

#endif // TWOSTEPCOLLIDER_H
