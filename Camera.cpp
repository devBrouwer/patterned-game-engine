#include "glm.hpp"
#include "Camera.hpp"
#include "Renderer.hpp"

Camera::Camera( std::string aName, glm::vec3 aPosition )
:	GameObject(aName, aPosition )
{
	glm::vec3 eye = aPosition;
	glm::vec3 at ( 0.0f, 1.0f, 0.0f );
	glm::vec3 up ( 0.0f, 1.0f, 0.0f );
	//transform = glm::inverse( glm::lookAt( eye, at, up ) );
	transform = glm::translate(aPosition);
	//rotate(15.0f, glm::vec3(0.0f,0.0f,1.0f));
	projection = glm::perspective(  60.0f, 4.0f/3.0f, 0.1f, 150.0f  );
}

void Camera::setPosition(glm::vec3 aPosition){
    //glm::vec3 eye = aPosition;
	//glm::vec3 at ( 0.0f, 1.0f, 0.0f );
	//glm::vec3 up ( 0.0f, 1.0f, 0.0f );
	//transform = glm::inverse( glm::lookAt( eye, at, up ) );
//	changeX = aPosition.x - getLocation().x;
//	changeZ = aPosition.z - getLocation()
    //return glm::vec3( transform[3][0], transform[3][1], transform[3][2] );
    transform[3][0] = aPosition.x;
    transform[3][2] = aPosition.z;
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

std::string Camera::getNextMessage(){
    if(messages.empty())
        return "";
    else
        return messages.front();
}

void Camera::popMessage(){
    if(!messages.empty())
        messages.pop();
}

void Camera::accept(Visitor * visitor){
    visitor->visit(this);
    //acceptChildren(visitor);
}

glm::mat4 Camera::getProjection(){
    return projection;
}

void Camera::pushMessage(std::string message){
    messages.push(message);
}
