#include "glm.hpp"
#include "Camera.hpp"
#include "Renderer.hpp"

Camera::Camera( std::string aName, glm::vec3 aPosition )
:	GameObject(aName, aPosition )
{
	glm::vec3 eye = aPosition;
	glm::vec3 at ( 0.0f, 1.0f, 0.0f );
	glm::vec3 up ( 0.0f, 1.0f, 0.0f );
	transform = glm::inverse( glm::lookAt( eye, at, up ) );
	projection = glm::perspective(  60.0f, 4.0f/3.0f, 0.1f, 100.0f  );
}

Camera::~Camera()
{
	//dtor
}

void Camera::accept(Visitor * visitor){
    visitor->visit(this);
    //acceptChildren(visitor);
}

glm::mat4 Camera::getProjection(){
    return projection;
}
