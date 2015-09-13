#ifndef __GAME_COMPONENT_VISITORS_HPP
#define __GAME_COMPONENT_VISITORS_HPP

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


class GameTransformComponents;
class GameCameraComponents;
class GameGeometryComponents;
class GameRigidBodyComponents;
class GameRenderMeshComponents;
class GameLightsComponents;
class GameBoxCollisionComponents;
class GameCubeMeshComponents;
class GameTerrainMeshComponents;
class GameTerrainColliderComponents;
class GamePropertiesComponents;
class IGameComponents;

class GameComponentVisitor
{
public:
	virtual void Visit(GameTransformComponents *v){}
	virtual void Visit(GameCameraComponents *v){}
	virtual void Visit(GameGeometryComponents *v){}
	virtual void Visit(GameRigidBodyComponents *v){}
	virtual void Visit(GameRenderMeshComponents *v){}
	virtual void Visit(GameLightsComponents *v){}
	virtual void Visit(GameBoxCollisionComponents *v){}
	virtual void Visit(GameCubeMeshComponents *v){}
	virtual void Visit(GameTerrainMeshComponents *v){}
	virtual void Visit(GameTerrainColliderComponents *v){}
	virtual void Visit(GamePropertiesComponents *v) {}
	virtual void Visit(IGameComponents *v) {}

	virtual void Update()=0;
	virtual void Reset()=0;
};


// TODO: write here different types of visitors that handles the different types of components
class MoveObjectVisitor : public GameComponentVisitor
{
	float _left;
	float _up;
	float _forward;
	GameTransformComponents *_transform;
	GameGeometryComponents *_geometry;
	GameBoxCollisionComponents *_boxCollisions;

public:
			 MoveObjectVisitor();
	virtual ~MoveObjectVisitor();

	void Visit(GameTransformComponents *v);

	void Visit(GameGeometryComponents *v);

	void Visit(GameBoxCollisionComponents *v);

	void Reset();

	void MoveLeft(float s);

	void MoveRight(float s);

	void Update();

};

class GravityVisitor : public GameComponentVisitor
{
public:
	
};

/*
class TestBoxCollisionsVisitor : public GameComponentVisitor
{
private:
	GameBoxCollisionComponents *_boxCollisions;
public:
	TestBoxCollisionsVisitor() {}
	virtual ~TestBoxCollisionsVisitor() {}

	void Visit(GameBoxCollisionComponents* v)
	{
		this->_boxCollisions = v;
	}

	void Reset()
	{
		this->_boxCollisions = NULL;
	}	

	void Update()
	{
		// Do something with the objects
	}
};


class ManagePropertiesValueVisitor : public GameComponentVisitor
{
private:
	GamePropertiesComponents *_properties;
public:
	ManagePropertiesValueVisitor() {}
	virtual ~ManagePropertiesValueVisitor() {}

	void Visit(GamePropertiesComponents* v)
	{
		this->_properties = v;
	}

	void Reset()
	{
		this->_properties = NULL;
	}

	bool CheckPropertiesEqualTo(std::string propertiesname, std::string comparevalue)
	{
		if (this->_properties->IsProperties(propertiesname, comparevalue))
			return true;
		else
			return false;
	}

	void Update()
	{
		// Do something with the objects
	}
};


class HandleSwitchVisitor : public GameComponentVisitor
{
private:
	GameSwitchComponents *_switches;
public:
	HandleSwitchVisitor() {}
	virtual ~HandleSwitchVisitor() {}

	void Visit(GameSwitchComponents* v)
	{
		this->_switches = v;
	}

	void Reset()
	{
		this->_switches = NULL;
	}

	bool GetSwitch(std::string switchname)
	{
		return this->_switches->GetSwitch(switchname);
	}

	void SetSwitch(std::string switchname, bool newbooleanvalue)
	{
		this->_switches->SetSwitch(switchname, newbooleanvalue);
	}

	void Update()
	{
		// Do something with the objects
	}
};
*/

#endif // __GAME_COMPONENT_VISITORS_HPP