#ifndef __GAME_COMPONENTS_HPP
#define __GAME_COMPONENTS_HPP

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

#include "objects.hpp"
#include "componentvisitors.hpp"

class GameComponentVisitor;
// 

//

class IGameComponents
{
public:
	virtual void Accept(GameComponentVisitor *visitor) = 0;
	virtual void Update(float dt) = 0;
	virtual std::string GetComponentsType()=0;

	void Enable()
	{ _isEnable = true; }

	void Disable()
	{ _isEnable = false; }

	bool IsEnable()
	{ return _isEnable; }

	// Returns the title of the components
	std::string GetTitle()
	{ return this->_title; }

private:
	bool _isEnable;

protected:
	std::string _title;
};


class GameTransformComponents : public IGameComponents
{
public:
			 GameTransformComponents();
	virtual ~GameTransformComponents();
	
	void SetPosition(const glm::vec3& pos);
	const glm::vec3 GetPosition() const;

	void SetRotation(const glm::vec3& r);
	const glm::vec3 GetRotation() const;
	
	void SetScale(const glm::vec3& s);
	const glm::vec3 GetScale() const;

	glm::mat4 GetModelMatrix();

	void Update(float dt);

	void Accept(GameComponentVisitor *visitor);

	std::string GetComponentsType();

private:
	glm::vec3 _position;
	glm::vec3 _rotation;
	glm::vec3 _scale;

	glm::vec3 _up;
	glm::vec3 _right;
	glm::vec3 _direction;
	glm::vec3 _target;

	glm::mat4 _modelMatrix;
};

class GameLocationsComponents : public IGameComponents
{
public:
			 GameLocationsComponents();
	virtual ~GameLocationsComponents();
	
	void SetPosition(const glm::vec3& pos);

	const glm::vec3 GetPosition() const;

	void SetSceneID(const std::string& s);

	const std::string GetSceneID() const;

	void Update(float dt);

	void Accept(GameComponentVisitor *visitor);

	std::string GetComponentsType();

private:
	glm::vec3 _position;
	std::string _sceneID;
};

class GameCameraComponents : public IGameComponents
{
public:
	GameCameraComponents();
	virtual ~GameCameraComponents();
	
	void Update(float dt);

	void Accept(GameComponentVisitor *visitor);

	std::string GetComponentsType();

};

class GameRenderMeshComponents : public IGameComponents
{
public:
			 GameRenderMeshComponents();
	virtual ~GameRenderMeshComponents();

	void Update(float dt);

	void Accept(GameComponentVisitor *visitor);

	std::string GetComponentsType();

};

// This is the mesh for a cube
class GameCubeMeshComponents : public IGameComponents
{
public:
			 GameCubeMeshComponents();
	virtual ~GameCubeMeshComponents();

	void Update(float dt);

	void Accept(GameComponentVisitor *visitor);

	std::string GetComponentsType();
};

// This is a plane with 
class GameTerrainMeshComponents : public IGameComponents
{
public:
			 GameTerrainMeshComponents();
	virtual ~GameTerrainMeshComponents();

	void Update(float dt);

	void Accept(GameComponentVisitor *visitor);

	std::string GetComponentsType();

};

// Collisions with the terrain-plane
class GameTerrainColliderComponents : public IGameComponents
{
public:
			 GameTerrainColliderComponents();
	virtual ~GameTerrainColliderComponents();

	void Update(float dt);

	void Accept(GameComponentVisitor *visitor);

	std::string GetComponentsType();

};

// Collisionscomponents for a box (AABB)
class GameBoxCollisionComponents : public IGameComponents
{
private:
	glm::vec3 _center;
	glm::vec3 _size;
	bool _isTrigger;	// this decides if its a trigger or regular collision. If trigger than use of enterTrigger, exitTrigger is available

public:
			 GameBoxCollisionComponents(glm::vec3 center, glm::vec3 size);
	virtual ~GameBoxCollisionComponents();

	void Update(float dt);

	void Accept(GameComponentVisitor *visitor);

	std::string GetComponentsType();

};

class GameLightsComponents : public IGameComponents
{
private:
	int spotlight, arealight;
public:
			 GameLightsComponents();
	virtual ~GameLightsComponents();

	void Update(float dt);

	void Accept(GameComponentVisitor *visitor);

	std::string GetComponentsType();

};

class GameRigidBodyComponents : public IGameComponents
{
private:

public:
			 GameRigidBodyComponents();
	virtual ~GameRigidBodyComponents();

	void Update(float dt);

	void Accept(GameComponentVisitor *visitor);

	std::string GetComponentsType();

};

// Geometry component with an visitor 
class GameGeometryComponents : public IGameComponents
{
public:
			 GameGeometryComponents(Mesh* M);
	virtual ~GameGeometryComponents();

	void Accept(GameComponentVisitor *visitor);

	void SetMesh(Mesh* M);

	void Update(float dt);

	std::string GetComponentsType();


	const Mesh* GetMesh() const;

private:
	Mesh* _mesh;
};


// PropertiesComponents stores informations of anykind, forinstance gamemetainformation about the entity.
class GamePropertiesComponents : public IGameComponents
{
public:
			 GamePropertiesComponents();

	virtual ~GamePropertiesComponents();

	void Accept(GameComponentVisitor *visitor);

	void SetProperties(std::string name, std::string values);

	std::string GetProperties(std::string name);

	bool IsProperties(std::string name, std::string value);

	void Update(float dt);

	std::string GetComponentsType();

private:
	std::map<std::string, std::string> _properties;
};

class GameSwitchComponents : public IGameComponents
{
public:
			 GameSwitchComponents();
	virtual ~GameSwitchComponents();

	void Accept(GameComponentVisitor *visitor);

	void SetSwitch(std::string name, bool values);
	bool GetSwitch(std::string name);
	void Update(float dt);
	std::string GetComponentsType();

private:
	std::map<std::string, bool> _switches;	
};

class GameBehaviourTreeComponents : public IGameComponents
{
public:
			 GameBehaviourTreeComponents();
	virtual ~GameBehaviourTreeComponents();

	void Accept(GameComponentVisitor *visitor);

	void SetBehaviourTree();
	bool GetBehaviourTree();
	void Update(float dt);
	std::string GetComponentsType();

private:		
};

#endif // __GAME_COMPONENTS_HPP