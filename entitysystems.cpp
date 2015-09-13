#include "entitysystems.hpp"



const std::string GameEntitySystems::GenerateUniqueID()
{
	boost::uuids::uuid uuid = boost::uuids::random_generator()();
	std::string tmp = boost::lexical_cast<std::string>(uuid);

	while (_entities.find(tmp) != _entities.end())
	{
		tmp = boost::lexical_cast<std::string>(uuid);
	}

	return 	tmp;	
}

GameEntitySystems::GameEntitySystems(){}
GameEntitySystems::~GameEntitySystems(){}

void GameEntitySystems::AddEntity(GameEntity *e)
{
	_entities[e->GetID()] = e;
}

void GameEntitySystems::CreateEmptyObject()
{
	std::string uuid = GenerateUniqueID();

	_entities[uuid] = new GameEntity(uuid);
	_entities[uuid]->SetName("EMPTY");
}

void GameEntitySystems::CreateCameraObject()
{
	std::string uuid = GenerateUniqueID();

	_entities[uuid] = new GameEntity(uuid);
	_entities[uuid]->SetName("CAMERA");	
	// Some other components need to be added here
	_entities[uuid]->AddComponents(new GameCameraComponents());	
}

void GameEntitySystems::CreateLamp()
{
	std::string uuid = GenerateUniqueID();

	_entities[uuid] = new GameEntity(uuid);
	_entities[uuid]->SetName("LAMP");
	// Some other components need to be added here
	_entities[uuid]->AddComponents(new GameLightsComponents());			
}

void GameEntitySystems::CreateBox()
{
	std::string uuid = GenerateUniqueID();

	_entities[uuid] = new GameEntity(uuid);
	_entities[uuid]->SetName("BOX");
	// Some other components need to be added here
	_entities[uuid]->AddComponents(new GameCubeMeshComponents());
	_entities[uuid]->AddComponents(new GameBoxCollisionComponents(glm::vec3(0,0,0), glm::vec3(1,1,1)));			

}

void GameEntitySystems::CreateTrigger()
{}

void GameEntitySystems::RemoveEntity(std::string ID)
{

}

GameEntity *GameEntitySystems::UseEntity(std::string ID)
{
	std::map<std::string, GameEntity *>::iterator itr = _entities.find(ID);

	if (itr != _entities.end())
	{
		return itr->second;
	}

	_entities[ID] = new GameEntity(ID);
	return _entities[ID];
}

GameEntity *GameEntitySystems::FindFirstEntityByName(std::string name)
{
	for (std::map<std::string, GameEntity *>::iterator itr = _entities.begin(); itr != _entities.end(); ++itr)
	{
		if (itr->second->GetName() == name)
			return itr->second;
	}

	return nullptr;
}

GameEntity *GameEntitySystems::FindFirstEntityByTag(std::string tag)
{
	for (std::map<std::string, GameEntity *>::iterator itr = _entities.begin(); itr != _entities.end(); ++itr)
	{
		if (itr->second->GetTag() == tag)
			return itr->second;
	}

	return nullptr;
}


// Request for a unique ID that hasn't been used yet in the entitysystem for any other objects
std::string GameEntitySystems::RequestsForUniqueID()
{
	return GenerateUniqueID();
}

void GameEntitySystems::ShowInfoAboutEntitys()
{
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "Entity Informations " << std::endl;

	for (std::map<std::string, GameEntity *>::iterator itr = _entities.begin(); itr != _entities.end(); ++itr)
	{
		GameEntity *e = itr->second;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "ID   : " << e->GetID() << std::endl;
		std::cout << "Name : " << e->GetName() << std::endl;
		std::cout << "Tag  : " << e->GetTag() << std::endl;
		std::cout << "Components : " << std::endl;

		std::map<std::string, IGameComponents *> c = e->GetComponents();
		
		for (std::map<std::string, IGameComponents *>::iterator itr = c.begin(); itr != c.end(); itr++)
		{
			std::cout << " - " << itr->second->GetTitle() << std::endl;
		}
	}

	std::cout << "----------------------------------------------------------------" << std::endl;
	
}

std::vector<std::string> GameEntitySystems::GetListOfEntityName()
{
	std::vector<std::string> _list;

	for (std::map<std::string, GameEntity *>::iterator itr = _entities.begin(); itr != _entities.end(); ++itr)
	{
		_list.push_back(itr->second->GetName());
	}

	return _list;
}

std::vector<std::string> GameEntitySystems::GetListOfEntityTag()
{
	std::vector<std::string> _list;

	for (std::map<std::string, GameEntity *>::iterator itr = _entities.begin(); itr != _entities.end(); ++itr)
	{
		_list.push_back(itr->second->GetTag());
	}

	return _list;
}

// this returns a list of entitys ID that has the tag, which could be useful when you group entity
// and want to be sure that you got all the entitys with a particular tag. forinstance all lights, all the triggers
// or all the monster, all the cameras etc. 
std::vector<std::string> GameEntitySystems::GetGroupListOfEntityByTag(std::string tag)
{
	std::vector<std::string> _list;

	for (std::map<std::string, GameEntity *>::iterator itr = _entities.begin(); itr != _entities.end(); ++itr)
	{
		if (itr->second->GetTag() == tag)
			_list.push_back(itr->second->GetID());
	}

	return _list;
}

// TODO: Do more with different operations here!.........

void GameEntitySystems::UseOperator(GameComponentVisitor *operators)
{
	for (std::map<std::string, GameEntity *>::iterator itr = _entities.begin(); itr != _entities.end(); ++itr)
	{
		itr->second->UseOperator(operators);
	}		
}