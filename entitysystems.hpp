#ifndef __GAME_ENTITIES_SYSTEMS_HPP
#define __GAME_ENTITIES_SYSTEMS_HPP

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

//#include "components.hpp"
//#include "componentvisitors.hpp"
#include "entites.hpp"

// And for last we have a system that handles our entitys and their components and use operators
// so we dont have to bother with details again. It has an interface that users are used
// Of course you can have several of this entitysystems holding differents entitys
class GameEntitySystems
{
private:
	std::map<std::string, GameEntity *> _entities;
	
	const std::string GenerateUniqueID();

public:
			 GameEntitySystems();
	virtual ~GameEntitySystems();

	void AddEntity(GameEntity *e);

	void CreateEmptyObject();

	void CreateCameraObject();

	void CreateLamp();

	void CreateBox();

	void CreateTrigger();

	void RemoveEntity(std::string ID);

	GameEntity *UseEntity(std::string ID);

	GameEntity *FindFirstEntityByName(std::string name);

	GameEntity *FindFirstEntityByTag(std::string tag);


	// Request for a unique ID that hasn't been used yet in the entitysystem for any other objects
	std::string RequestsForUniqueID();

	void ShowInfoAboutEntitys();

	std::vector<std::string> GetListOfEntityName();

	std::vector<std::string> GetListOfEntityTag();

	// this returns a list of entitys ID that has the tag, which could be useful when you group entity
	// and want to be sure that you got all the entitys with a particular tag. forinstance all lights, all the triggers
	// or all the monster, all the cameras etc. 
	std::vector<std::string> GetGroupListOfEntityByTag(std::string tag);

	// TODO: Do more with different operations here!.........

	void UseOperator(GameComponentVisitor *operators);
};



#endif // __GAME_ENTITIES_SYSTEMS_HPP