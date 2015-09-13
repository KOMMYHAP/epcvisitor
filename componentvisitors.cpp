#include "componentvisitors.hpp"

MoveObjectVisitor::MoveObjectVisitor(){ this->_left = 0.0f; }
MoveObjectVisitor::~MoveObjectVisitor(){}

void MoveObjectVisitor::Visit(GameTransformComponents *v)
{	
	this->_transform = v;
}

void MoveObjectVisitor::Visit(GameGeometryComponents *v)
{
	this->_geometry = v;	
}

void MoveObjectVisitor::Visit(GameBoxCollisionComponents *v)
{
	// calculate all the details about this, when moving the boxcollisionsobjekt
	
	this->_boxCollisions = v;
}

void MoveObjectVisitor::Reset()
{
	this->_boxCollisions = NULL;
	this->_geometry = NULL;
	this->_transform = NULL;
}

void MoveObjectVisitor::MoveLeft(float s)
{ this->_left = s; }

void MoveObjectVisitor::MoveRight(float s)
{ this->_left = -s; }

void MoveObjectVisitor::Update()
{
	glm::vec3 p = this->_transform->GetPosition();
	p.x += this->_left;
	this->_transform->SetPosition(p);
	std::cout << p.x << " " << p.y << " " << p.z << std::endl;
	std::cout << "moving the objects transformation component" << std::endl;
	std::cout << "moving the objects box collision component" << std::endl;
	std::cout << "moving the objects geometry component" << std::endl;
}

////////////////////////////////////////////////////////////