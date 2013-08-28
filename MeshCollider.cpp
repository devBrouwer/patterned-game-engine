#include "MeshCollider.hpp"
#include "GameObject.hpp"
#include "Mesh.hpp"

MeshCollider::MeshCollider(GameObject * aParent) : Collider(aParent)
{
    //ctor
}

MeshCollider::~MeshCollider()
{
    //dtor
}

bool MeshCollider::collides(Collider * otherCollider, bool reportCollision){
    //std::cout << "IN mesh collider.collides " << std::endl;
    std::vector<glm::vec3> vertices = parent->getMesh()->getVertices();
    for(std::vector<glm::vec3>::iterator it = vertices.begin(); it != vertices.end(); ++it){
        glm::vec4 location4 = parent->getTransform() * glm::vec4((*it).x,(*it).y,(*it).z,1.0f);
        glm::vec3 location = glm::vec3(location4.x / location4.w, location4.y/location4.w, location4.z / location4.w);
        float distance = glm::distance(location, otherCollider->getParent()->getLocation());
        if ( distance < otherCollider->getRadius() ) {
            if(reportCollision){
                std::cout << "MESH COLLIDER collision at: " << location << std::endl;
                getParent()->onCollision(otherCollider->getParent());
            }
            return true;
        }
    }
    return false;
}
