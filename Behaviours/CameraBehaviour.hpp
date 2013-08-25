#ifndef CAMERABEHAVIOUR_HPP
#define CAMERABEHAVIOUR_HPP

#include "../Behaviour.hpp"
#include "../Camera.hpp"


class CameraBehaviour : public Behaviour
{
    public:
        /** Default constructor */
        CameraBehaviour(Camera * camera, GameObject * followThis);
        /** Default destructor */
        virtual ~CameraBehaviour();
        virtual void update(float step);
    protected:
    private:
        GameObject * followThis;
        const static float cameradist = 20.0f;
};

#endif // CAMERABEHAVIOUR_HPP
