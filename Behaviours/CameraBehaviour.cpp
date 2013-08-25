#include "CameraBehaviour.hpp"
#include <Math.h>

CameraBehaviour::CameraBehaviour(Camera * camera, GameObject * followThis) : Behaviour((GameObject*)camera), followThis(followThis)
{
    //ctor
}

CameraBehaviour::~CameraBehaviour()
{
    //dtor
}

void CameraBehaviour::update( float step )
{
    Camera * cam = (Camera*)followThis;
    glm::vec3 objectPosition = followThis->getLocation();
    cam->setPosition(followThis->getLocation());

    float camerax = cameradist * cos((0 + 270.0f) * M_PI / 180) + objectPosition.x;
    float cameraz = cameradist * sin((0 - 270.0f) * M_PI / 180) + objectPosition.z;

    cam->setPosition(glm::vec3(camerax, 0.0f, cameraz));
}
