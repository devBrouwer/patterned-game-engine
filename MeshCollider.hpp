#ifndef MESHCOLLIDER_H
#define MESHCOLLIDER_H

#include "Collider.hpp"


class MeshCollider : public Collider
{
    public:
        /** Default constructor */
        MeshCollider(GameObject * aParent);
        /** Default destructor */
        virtual ~MeshCollider();
        bool collides(Collider * otherCollider);
    protected:
    private:
};

#endif // MESHCOLLIDER_H
