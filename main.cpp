// This could be used when you create an ECS system , entity, component system
// and don't want to handle all the details. Visitors helps 
// visit the component and knows what to do, and do their operations on it
// Visitor pattern is like adding operators to a component without bother with the details
// There are other way to create an ECS system. But this ECS is based on the design pattern visitors

// g++ main.cpp components.cpp componentvisitors.cpp entites.cpp entitysystems.cpp -o main

#include <iostream>
#include <vector>
#include <map>
#include <time.h>
#include <string>
#include <sstream>

#include <boost/uuid/uuid.hpp>            // uuid class
#include <boost/uuid/uuid_generators.hpp> // generators
#include <boost/uuid/uuid_io.hpp>         // streaming operators etc.
#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid_io.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp> 		// to use glm::value_ptr
#include <glm/gtx/string_cast.hpp> 		// to use glm::to_string
#include <glm/gtx/transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtc/matrix_transform.hpp> // to use glm::perspective och glm::rotate

#include "components.hpp"
#include "componentvisitors.hpp"
#include "entites.hpp"
#include "entitysystems.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////////

// Important step here!
/*
class GameEntity
{
private:
	std::string _id;
	std::string _name;
	std::string _tag;

	std::map<std::string, IGameComponents *> _components;

	void Init()
	{
		// Every entity has transform components on the base always
		// because every entity expect to have positions, rotations attributes
		AddComponents(new GameTransformComponents());
	}

public:
	GameEntity(std::string ID, std::string name, std::string tag)
	{
		this->_id = ID;
		this->_name = name;
		this->_tag = tag;
		Init();
	}

	GameEntity(std::string ID, std::string name)
	{
		this->_id = ID;
		this->_name = name;
		Init();
	}

	GameEntity(std::string ID)
	{
		this->_id = ID;
		Init();
	}

	virtual ~GameEntity(){}

	void SetName(std::string name)
	{ this->_name = name; }

	void SetTag(std::string tag)
	{ this->_tag = tag; }

	std::string GetName()
	{ return this->_name; }

	std::string GetTag()
	{ return this->_tag; }

	std::string GetID()
	{ return this->_id; }

	void AddComponents(IGameComponents *c)
	{
		_components[c->GetComponentsType()] = c;
	}

	std::map<std::string, IGameComponents *> GetComponents()
	{
		return this->_components;
	}

	IGameComponents* UseComponents(std::string name)
	{
		return _components[name];
	}

	// Use operators on a specific components directly
	void QuickUseOperator(std::string componentName, GameComponentVisitor *operators)
	{
		// Always reset the connections before
		operators->Reset();

		_components[componentName]->Accept(operators);
	}

	// Use operators on a specific components
	void UseOperator(std::string componentName, GameComponentVisitor *operators)
	{
		std::map<std::string, IGameComponents *>::iterator itr = _components.find(componentName);

		if (itr != _components.end())
		{
			// Always reset the connections before
			operators->Reset();

			itr->second->Accept(operators);
		}
	}

	// use operators on all components. You don't have to bother remeber which components
	// an entity has
	void UseOperator(GameComponentVisitor *operators)
	{
		// Always reset the connections before
		operators->Reset();

		for (std::map<std::string, IGameComponents *>::iterator itr = _components.begin(); itr != _components.end(); ++itr)
		{
			itr->second->Accept(operators);
		}
	}
};

*/
int main(int argc, char** argv)
{
	
	// With this way we don't have to bother with the details 
	// on what kind of the components we are dealing with.
	// the operator decides what to do.
	// Important step is that the components has to be holding data
	// and letting the visitor operations get access to it, thats all. Visitor decides than what to do with it
	// based ofcourse what you have inparameters. Look how simple it could be!

	
	//std::vector<IGameComponents *> _components;

	//_components.push_back(new GameTransformComponents());
	//_components.push_back(new GameGeometryComponents(new Mesh()));

	// And now the operator that we will use on the components 

	//MoveObjectVisitor move; //  = new MoveObjectVisitor();
	//_components[1]->Accept(&move);
	//_components[0]->Accept(&move);
	

	// Firstly we create a entity system that holds and simplify our entity creations
	GameEntitySystems *es = new GameEntitySystems();

	// Quick create new entitys
	es->CreateEmptyObject();
	es->CreateBox();

	// This is another way to create an entity
	std::string id = es->RequestsForUniqueID();
	es->AddEntity(new GameEntity(id, "test"));

	// This is how we can use entity
	//std::cout << "object : " << id << " has the name " << es->UseEntity(id)->GetName() << std::endl;

	// Show all the informations about the entitys we got so far
	es->ShowInfoAboutEntitys();

	// Create an operators
	MoveObjectVisitor m;

	// Find the entity
	GameEntity *e1 = es->FindFirstEntityByName("BOX");

	// Add a new components to it
	e1->AddComponents(new GameBoxCollisionComponents(glm::vec3(0,0,0), glm::vec3(5,5,5)));

	//GameTransformComponents *t = (GameTransformComponents*)(e1->UseComponents("TRANSFORM"));
	//t->SetPosition(glm::vec3(2,0,5));

	// Associate the entity with the operators
	e1->UseOperator(&m);

	// Now we can manage and operate with our components via the operators
	m.MoveLeft(0.1f);
	m.Update();

	// Here we go again, find a new entity
	GameEntity *e2 = es->FindFirstEntityByName("EMPTY");

	// Associate the same operators
	e2->UseOperator(&m);

	// And than we control via the operators
	m.MoveLeft(1.1f);
	m.Update();
	

	return 0;
};