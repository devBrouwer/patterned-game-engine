#ifndef RECTANGULARPRISMCOLLIDER_HPP
#define RECTANGULARPRISMCOLLIDER_HPP

#include "Collider.hpp"
#include "GameObject.hpp"


class RectangularPrismCollider : public Collider
{
    public:
        /** Default constructor */
        RectangularPrismCollider(GameObject * aParent, glm::vec3 start, glm::vec3 end);
        /** Default destructor */
        virtual ~RectangularPrismCollider();


		virtual bool collides( Collider * otherCollider );
		virtual void accept(Visitor * visitor);
    protected:
    private:
        glm::vec3 start;
        glm::vec3 end;
};

#endif // RECTANGULARPRISMCOLLIDER_HPP
