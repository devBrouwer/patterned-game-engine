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
	projection = glm::perspective(  60.0f, 4.0f/3.0f, 0.1f, 150.0f  );
}

void Camera::setPosition(glm::vec3 aPosition){
    glm::vec3 eye = aPosition;
	glm::vec3 at ( 0.0f, 1.0f, 0.0f );
	glm::vec3 up ( 0.0f, 1.0f, 0.0f );
	transform = glm::inverse( glm::lookAt( eye, at, up ) );
}

void Camera::translate( glm::vec3 translation )
{
	transform = glm::translate( transform, translation );
	for ( std::vector< GameObject * >::iterator i = children.begin(); i != children.end(); ++i ) {
        ((GameObject * )*i)->translate( translation );
    }
}


void Camera::rotate( float angle, glm::vec3 axis )
{
	transform = glm::rotate( transform, angle, axis);
    for ( std::vector< GameObject * >::iterator i = children.begin(); i != children.end(); ++i ) {
        ((GameObject * )*i)->rotate( angle, axis );
    }
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
