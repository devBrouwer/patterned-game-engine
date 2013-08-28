#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <string>
#include "glm.hpp"
#include "Visitor.hpp"
#include "Visitable.hpp"

class Transform;
class Collider;
class Renderer;
class Mesh;
class Texture;
class Behaviour;

class GameObject : public Visitable
{
	protected:
		std::string name;
		glm::mat4 transform;
		Collider * collider;
		Behaviour * behaviour;

		Mesh * mesh;
		Texture * colorMap;

        GameObject * parent;
		std::vector< GameObject * > children;

	public:
	    GameObject * getParent();
	    void setParent(GameObject * theParent);
	    virtual glm::mat4 getTransform();

	    GameObject( std::string aName, glm::mat4 aTransform);
		GameObject( std::string aName = NULL, glm::vec3 aPosition = glm::vec3( 0.0f, 0.0f, 0.0f ) );
		virtual ~GameObject();

		virtual void translate( glm::vec3 translation );
		virtual void rotate( float angle, glm::vec3 axis );

		const std::string getName();
		glm::vec3 getLocation();
		bool hasCollider();
		bool hasMesh();

		void setBehaviour( Behaviour * aBehaviour );
		void setCollider( Collider * aCollider );
		void setMesh( Mesh * aMesh );
		void setColorMap( Texture * aColorMap );

		Texture * getColorMap();
		Collider * getCollider();
		Mesh * getMesh();

		virtual void update( float step );
		virtual bool collides( GameObject * otherGameObject );
		virtual void onCollision(  GameObject * otherGameObject );

		virtual void accept(Visitor * visitor);
		virtual void acceptChildren(Visitor * visitor);

		virtual void add( GameObject * child );

	protected:

};

#endif // GAMEOBJECT_H
