#include <cassert>
#include <iostream>

#include "Renderer.hpp"
#include "GameObject.hpp"
#include "Collider.hpp"
#include "Behaviour.hpp"
#include "Mesh.hpp"
#include "Texture.hpp"

GameObject::GameObject( std::string aName, glm::vec3 aPosition )
:	name( aName ), transform( glm::translate( aPosition ) ), collider( NULL ), behaviour( NULL ), mesh( NULL ), colorMap( NULL ), parent( NULL )
{
}

GameObject::~GameObject()
{
	//dtor
}

void GameObject::translate( glm::vec3 translation )
{
	transform = glm::translate( transform, translation );
}

void GameObject::rotate( float angle, glm::vec3 axis )
{
	transform = glm::rotate( transform, angle, axis);
}

const std::string GameObject::getName()
{
	return name;
}

glm::vec3 GameObject::getLocation()
{
	return glm::vec3( transform[3][0], transform[3][1], transform[3][2] );
}

bool GameObject::hasCollider()
{
	return collider != NULL;
}

bool GameObject::hasMesh(){
    return mesh != NULL;
}

void GameObject::setBehaviour( Behaviour * aBehaviour )
{
	assert( aBehaviour != NULL );
	behaviour = aBehaviour;
}

void GameObject::setCollider( Collider * aCollider )
{
	assert( aCollider != NULL );
	collider = aCollider;
}


void GameObject::setMesh( Mesh * aMesh )
{
	assert( aMesh != NULL );
	mesh = aMesh;
}

void GameObject::setColorMap( Texture * aColorMap )
{
	assert( aColorMap != NULL );
	assert( aColorMap->getId() > 0 );
	colorMap = aColorMap;
}

void GameObject::update( float step )
{
	if ( behaviour ) {
		behaviour->update( step );
	}
	for ( std::vector< GameObject * >::iterator i = children.begin(); i != children.end(); ++i ) {
		((GameObject * )*i)->update( step );
	}

}

glm::mat4 GameObject::getTransform(){
    if(parent != NULL ){
        return parent->getTransform() * transform;
    }
    else{
        return transform;
    }
}


bool GameObject::collides( GameObject * otherGameObject )
{
	assert( collider != NULL );
	assert( otherGameObject != NULL );
	assert( otherGameObject->collider != NULL );
	return collider->collides( otherGameObject->collider );
}

void GameObject::onCollision(  GameObject * otherGameObject )
{
	if ( behaviour ) {
		behaviour->onCollision( otherGameObject );
	}
}

void GameObject::draw( Renderer * aRenderer, glm::mat4 parentTransform )
{
	assert( aRenderer != NULL );

	//std::cout << name << "  ";
	if ( mesh ) { // if there is something to draw
		aRenderer->setModel( parentTransform * transform ); // combine parents transfor with own
		if ( colorMap ) { //is has a colormap
			aRenderer->setColorMap( colorMap );
		}
		mesh->draw( aRenderer );
	}
	// draw children
	for ( std::vector< GameObject * >::iterator i = children.begin(); i != children.end(); ++i ) {
		((GameObject * )*i)->draw( aRenderer, parentTransform * transform );
	}
}

Texture * GameObject::getColorMap(){
    return this->colorMap;
}

void GameObject::add( GameObject * child )
{
	assert( child != NULL );
	children.push_back( child );
	child->setParent(this);
}

void GameObject::setParent(GameObject * theParent){
    parent = theParent;
}

void GameObject::accept(Visitor * visitor){
    visitor->visit(this);
    if(mesh){
        mesh->accept(visitor);
    }
    if(behaviour){
        behaviour->accept(visitor);
    }
    if(collider){
        collider->accept(visitor);
    }
    acceptChildren(visitor);
}

void GameObject::acceptChildren(Visitor * visitor){
    for ( std::vector< GameObject * >::iterator i = children.begin(); i != children.end(); ++i ) {
        ((GameObject * )*i)->accept(visitor);
	}
}

GameObject * GameObject::getParent(){
    return this->parent;
}

// private functions

