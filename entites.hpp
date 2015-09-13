#ifndef __GAME_ENTITIES_HPP
#define __GAME_ENTITIES_HPP

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

////////////////////////////////////////////////////////////////////////////////////////////////////////

// Important step here!

class GameEntity
{
private:
	std::string _id;
	std::string _name;
	std::string _tag;

	std::map<std::string, IGameComponents *> _components;

	void Init();

public:
	GameEntity(std::string ID, std::string name, std::string tag);
	GameEntity(std::string ID, std::string name);
	GameEntity(std::string ID);
	virtual ~GameEntity();

	void SetName(std::string name);
	void SetTag(std::string tag);

	std::string GetName();

	std::string GetTag();

	std::string GetID();

	void AddComponents(IGameComponents *c);

	std::map<std::string, IGameComponents *> GetComponents();

	IGameComponents* UseComponents(std::string name);

	// Use operators on a specific components directly
	void QuickUseOperator(std::string componentName, GameComponentVisitor *operators);

	// Use operators on a specific components
	void UseOperator(std::string componentName, GameComponentVisitor *operators);

	// use operators on all components. You don't have to bother remeber which components
	// an entity has
	void UseOperator(GameComponentVisitor *operators);
};


#endif // __GAME_ENTITIES_HPP