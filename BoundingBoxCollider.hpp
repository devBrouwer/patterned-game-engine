#ifndef BOUNDINGBOXCOLLIDER_H
#define BOUNDINGBOXCOLLIDER_H

#include "Collider.hpp"


class BoundingBoxCollider : public Collider
{
    public:
        /** Default constructor */
        BoundingBoxCollider(GameObject * aParent, float xMin, float xPlus, float yMin, float yPlus, float zMin, float zPlus);
        /** Default destructor */
        virtual ~BoundingBoxCollider();
    protected:
    private:
        //linksondervoor = xMin,yMin, zMin;
        //rechtsbovenachter = xPlus,yPlus,zPlus;
        float xMin;
        float xPlus;
        float yMin;
        float yPlus;
        float zMin;
        float zPlus;
};

#endif // BOUNDINGBOXCOLLIDER_H
