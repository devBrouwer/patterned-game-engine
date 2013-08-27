#ifndef PICKER_H
#define PICKER_H

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "Camera.hpp"

class Picker
{
	public:
		Picker(Camera * camera);
		virtual ~Picker();
		void pick( glm::vec2 mouse  );
		bool hits( glm::vec3 center, float radius );

	private:
		glm::vec3 org;
		glm::vec3 dir;
		Camera * camera;
};

#endif // PICKER_H
