#ifndef FOLLOWBEHAVIOUR_HPP
#define FOLLOWBEHAVIOUR_HPP

#include "../Behaviour.hpp"
#include "../Camera.hpp"


class FollowBehaviour : public Behaviour
{
    public:
        /** Default constructor */
        FollowBehaviour(Camera * aParent, GameObject * aFollowMe);
        /** Default destructor */
        virtual ~FollowBehaviour();
        virtual void update(float step);
    protected:
    private:
        GameObject * followMe;
};

#endif // FOLLOWBEHAVIOUR_HPP
