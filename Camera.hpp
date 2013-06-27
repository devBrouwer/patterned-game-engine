#ifndef CAMERA_H
#define CAMERA_H

#include <string>
#include "GameObject.hpp"

class Renderer;

class Camera : public GameObject
{
	private: //members
		glm::mat4 projection;

	public:
	    glm::mat4 getProjection();
	    void setPosition(glm::vec3);
		Camera( std::string aName = NULL, glm::vec3 aPosition = glm::vec3( 0.0f, 3.0f, 5.0f ) );
		virtual ~Camera();

		virtual void accept(Visitor * visitor);

};

#endif // CAMERA_H
