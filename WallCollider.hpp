#ifndef WALLCOLLIDER_HPP
#define WALLCOLLIDER_HPP

#include "Collider.hpp"
#include "GameObject.hpp"


class WallCollider : public Collider
{
    public:
        /** Default constructor */
        WallCollider(GameObject * aParent, glm::vec3 start, glm::vec3 end);
        /** Default destructor */
        virtual ~WallCollider();


		virtual bool collides( Collider * otherCollider );
		virtual void accept(Visitor * visitor);
    protected:
    private:
        glm::vec3 start;
        glm::vec3 end;
};

#endif // WALLCOLLIDER_HPP
