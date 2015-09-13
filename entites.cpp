#include "entites.hpp"



GameEntity::GameEntity(std::string ID, std::string name, std::string tag)
{
	this->_id = ID;
	this->_name = name;
	this->_tag = tag;
	Init();
}

GameEntity::GameEntity(std::string ID, std::string name)
{
	this->_id = ID;
	this->_name = name;
	Init();
}

GameEntity::GameEntity(std::string ID)
{
	this->_id = ID;
	Init();
}

GameEntity::~GameEntity(){}

void GameEntity::Init()
{
	// Every entity has transform components on the base always
	// because every entity expect to have positions, rotations attributes
	AddComponents(new GameTransformComponents());
}

void GameEntity::SetName(std::string name)
{ this->_name = name; }

void GameEntity::SetTag(std::string tag)
{ this->_tag = tag; }

std::string GameEntity::GetName()
{ return this->_name; }

std::string GameEntity::GetTag()
{ return this->_tag; }

std::string GameEntity::GetID()
{ return this->_id; }

void GameEntity::AddComponents(IGameComponents *c)
{
	_components[c->GetComponentsType()] = c;
}

std::map<std::string, IGameComponents *> GameEntity::GetComponents()
{
	return this->_components;
}

IGameComponents* GameEntity::UseComponents(std::string name)
{
	return _components[name];
}

// Use operators on a specific components directly
void GameEntity::QuickUseOperator(std::string componentName, GameComponentVisitor *operators)
{
	// Always reset the connections before
	operators->Reset();

	_components[componentName]->Accept(operators);
}

// Use operators on a specific components
void GameEntity::UseOperator(std::string componentName, GameComponentVisitor *operators)
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
void GameEntity::UseOperator(GameComponentVisitor *operators)
{
	// Always reset the connections before
	operators->Reset();

	for (std::map<std::string, IGameComponents *>::iterator itr = _components.begin(); itr != _components.end(); ++itr)
	{
		itr->second->Accept(operators);
	}
}