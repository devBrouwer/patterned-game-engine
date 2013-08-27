#include "Picker.hpp"


Picker::Picker(Camera * camera) : camera(camera)
{

}

Picker::~Picker()
{

}

void Picker::pick( glm::vec2 mouse )
{
	glm::vec2 screen( 800, 600 ); // from window
	glm::mat4 projection = camera->getProjection(); // from camera
	glm::mat4 view = glm::inverse(camera->getTransform());
	//glm::lookAt( glm::vec3( 0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f ), glm::vec3( 0.0f, 1.0f, 0.0f ) ); // from camera

	// get mouse coordinates in cam space ( screen space -> projection space (norm) -> cam space
	glm::vec3 point;
	point.x = -( 2.0f * mouse.x / screen.x -1 ) / projection[0][0]; //screen to norm p-space, mind scaling in projection for x,y
	point.y =  ( 2.0f * mouse.y / screen.y -1 ) / projection[1][1];
	point.z =  1.0f;

	// from cam to worldspace by inverse view
	glm::mat4 inverseView = glm::inverse( view );
	dir = glm::normalize( glm::vec3( inverseView * glm::vec4( point, 0.0f ) ) ); // get orientation ( dir ) and normalize
	org = glm::vec3( inverseView * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f) ); // get start point of ray ( eye of cam )
}

bool Picker::hits( glm::vec3 center, float radius )
{
	glm::vec3 oc = center - org; // from org to center
	glm::vec3 p = org + glm::dot( oc, dir ) * dir; // nearest point on ray to center
	return glm::length2( center - p ) < radius*radius ;
}
