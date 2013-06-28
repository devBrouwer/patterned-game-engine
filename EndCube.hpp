#ifndef ENDCUBE_HPP
#define ENDCUBE_HPP

#include "GameObject.hpp"
#include "Collider.hpp"


class EndCube : public GameObject
{
    public:
        /** Default constructor */
        EndCube(glm::vec3 position);
        /** Default destructor */
        virtual ~EndCube();
    protected:
    private:
};

#endif // ENDCUBE_HPP
