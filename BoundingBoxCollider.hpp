#ifndef BOUNDINGBOXCOLLIDER_H
#define BOUNDINGBOXCOLLIDER_H

#include "Collider.hpp"
#include "glm.hpp"


class BoundingBoxCollider : public Collider
{
    public:
        /** Default constructor */
        BoundingBoxCollider(GameObject * aParent, glm::vec3 start, glm::vec3 end);
        /** Default destructor */
        virtual ~BoundingBoxCollider();
        bool collides(Collider * otherCollider);
    protected:
    private:
        //linksondervoor = start
        //rechtsbovenachter = end;
        glm::vec3 start;
        glm::vec3 end;
};

#endif // BOUNDINGBOXCOLLIDER_H
