#include "Light.hpp"

#include "Renderer.hpp"

Light::Light( std::string aName, glm::vec3 aPosition )
:	GameObject( aName, aPosition )
{
}

Light::~Light()
{
	//dtor
}

void Light::accept(Visitor * visitor){
    visitor->visit(this);
    //acceptChildren(visitor);
}
