#include "FollowBehaviour.hpp"

FollowBehaviour::FollowBehaviour(Camera * aParent, GameObject * aFollowMe): Behaviour((GameObject*)aParent), followMe(aFollowMe)
{
    //ctor
}

FollowBehaviour::~FollowBehaviour()
{
    //dtor
}

void FollowBehaviour::update( float step )
{
    ((Camera*)parent)->setPosition(followMe->getLocation());
}
