#include "components.hpp"

GameTransformComponents::GameTransformComponents(){ this->_title = "Transform";}
GameTransformComponents::~GameTransformComponents(){}

void GameTransformComponents::SetPosition(const glm::vec3& pos)
{ this->_position = pos; }

const glm::vec3 GameTransformComponents::GetPosition() const
{ return this->_position; }

void GameTransformComponents::SetRotation(const glm::vec3& r)
{ this->_rotation = r; }

const glm::vec3 GameTransformComponents::GetRotation() const
{ return this->_rotation; }

void GameTransformComponents::SetScale(const glm::vec3& s)
{ this->_scale = s; }

const glm::vec3 GameTransformComponents::GetScale() const
{ return this->_scale; }

glm::mat4 GameTransformComponents::GetModelMatrix()
{ return _modelMatrix; }

void GameTransformComponents::Update(float dt)
{ }

std::string GameTransformComponents::GetComponentsType()
{ return "TRANSFORM"; }


////////////////////////////////////////////////////////////

GameCameraComponents::GameCameraComponents(){ this->_title = "Camera";}
GameCameraComponents::~GameCameraComponents(){}

void GameCameraComponents::Update(float dt)
{

}

std::string GameCameraComponents::GetComponentsType()
{ return "CAMERA"; }


////////////////////////////////////////////////////////////


GameLocationsComponents::GameLocationsComponents(){ this->_title = "Locations";}
GameLocationsComponents::~GameLocationsComponents(){}

void GameLocationsComponents::SetPosition(const glm::vec3& pos)
{ this->_position = pos; }

const glm::vec3 GameLocationsComponents::GetPosition() const
{ return this->_position; }

void GameLocationsComponents::SetSceneID(const std::string& s)
{ this->_sceneID = s; }

const std::string GameLocationsComponents::GetSceneID() const
{ return this->_sceneID; }

void GameLocationsComponents::Update(float dt)
{

}

std::string GameLocationsComponents::GetComponentsType()
{ return "LOCATIONS"; }


////////////////////////////////////////////////////////////


GameRenderMeshComponents::GameRenderMeshComponents(){this->_title = "Mesh Renderer";}
GameRenderMeshComponents::~GameRenderMeshComponents(){}

void GameRenderMeshComponents::Update(float dt)
{

}

std::string GameRenderMeshComponents::GetComponentsType()
{ return "RENDERMESH"; }

////////////////////////////////////////////////////////////


GameCubeMeshComponents::GameCubeMeshComponents() { this->_title = "Cube Mesh"; }
GameCubeMeshComponents::~GameCubeMeshComponents(){}

void GameCubeMeshComponents::Update(float dt)
{

}

std::string GameCubeMeshComponents::GetComponentsType()
{ return "CUBE_MESH"; }

////////////////////////////////////////////////////////////


GameTerrainMeshComponents::GameTerrainMeshComponents(){ this->_title = "Terrain Mesh"; }
GameTerrainMeshComponents::~GameTerrainMeshComponents(){}

void GameTerrainMeshComponents::Update(float dt)
{

}

std::string GameTerrainMeshComponents::GetComponentsType()
{ return "TERRAIN_MESH"; }

////////////////////////////////////////////////////////////

GameTerrainColliderComponents::GameTerrainColliderComponents(){ this->_title = "Terrain Collider"; }
GameTerrainColliderComponents::~GameTerrainColliderComponents() {}

void GameTerrainColliderComponents::Update(float dt)
{

}

std::string GameTerrainColliderComponents::GetComponentsType()
{ return "TERRAIN_COLLISIONS"; }


////////////////////////////////////////////////////////////

GameBoxCollisionComponents::GameBoxCollisionComponents(glm::vec3 center, glm::vec3 size)
{
	this->_center = center;
	this->_size = size;
	this->_isTrigger = false;
	this->_title = "Box Collision";
}

GameBoxCollisionComponents::~GameBoxCollisionComponents(){}

void GameBoxCollisionComponents::Update(float dt)
{

}

std::string GameBoxCollisionComponents::GetComponentsType()
{ return "BOX_COLLISIONS"; }

////////////////////////////////////////////////////////////

GameLightsComponents::GameLightsComponents(){ this->_title = "Light"; }
GameLightsComponents::~GameLightsComponents(){}

void GameLightsComponents::Update(float dt)
{

}

std::string GameLightsComponents::GetComponentsType()
{ return "LIGHTS"; }

////////////////////////////////////////////////////////////

GameRigidBodyComponents::GameRigidBodyComponents(){this->_title = "RigidBody";}
GameRigidBodyComponents::~GameRigidBodyComponents(){}

void GameRigidBodyComponents::Update(float dt)
{

}

std::string GameRigidBodyComponents::GetComponentsType()
{ return "RIGIDBODY"; }

////////////////////////////////////////////////////////////


GameGeometryComponents::GameGeometryComponents(Mesh* M)
 {
 	this->_mesh = M;
 	this->_title = "Geometry Mesh";
 }

GameGeometryComponents::~GameGeometryComponents(){
	delete this->_mesh;
}

void GameGeometryComponents::SetMesh(Mesh* M)
{ 
	if (M == NULL)
		return;

	this->_mesh = M;
}

void GameGeometryComponents::Update(float dt)
{

}

std::string GameGeometryComponents::GetComponentsType()
{ return "GEOMETRY"; }

const Mesh* GameGeometryComponents::GetMesh() const
{ return this->_mesh; }

////////////////////////////////////////////////////////////


GamePropertiesComponents::GamePropertiesComponents()
{
	this->_title = "Properties";
}

GamePropertiesComponents::~GamePropertiesComponents()
{
	// delete this->_mesh;
}

void GamePropertiesComponents::SetProperties(std::string name, std::string values)
{ 
	_properties[name] = values;
}

std::string GamePropertiesComponents::GetProperties(std::string name)
{
	return _properties[name];
}

bool GamePropertiesComponents::IsProperties(std::string name, std::string value)
{
	if (_properties[name] == value)
		return true;
	else
		return false;
}

void GamePropertiesComponents::Update(float dt)
{

}

std::string GamePropertiesComponents::GetComponentsType()
{ return "PROPERTIES"; }


////////////////////////////////////////////////////////////


GameSwitchComponents::GameSwitchComponents()
{
	this->_title = "Switches (on/off)";
}

GameSwitchComponents::~GameSwitchComponents()
{
	// delete this->_mesh;
}

void GameSwitchComponents::SetSwitch(std::string name, bool values)
{ 
	_switches[name] = values;
}

bool GameSwitchComponents::GetSwitch(std::string name)
{
	return _switches[name];
}

void GameSwitchComponents::Update(float dt)
{

}

std::string GameSwitchComponents::GetComponentsType()
{ return "SWITCHES"; }


////////////////////////////////////////////////////////////

void GameTransformComponents::Accept(GameComponentVisitor *visitor) { visitor->Visit(this); }
void GameCameraComponents::Accept(GameComponentVisitor *visitor) { visitor->Visit(this); }
void GameGeometryComponents::Accept(GameComponentVisitor *visitor) { visitor->Visit(this); }
void GameRenderMeshComponents::Accept(GameComponentVisitor *visitor) { visitor->Visit(this); }
void GameLightsComponents::Accept(GameComponentVisitor *visitor) { visitor->Visit(this); }
void GameRigidBodyComponents::Accept(GameComponentVisitor *visitor) { visitor->Visit(this); }
void GameTerrainMeshComponents::Accept(GameComponentVisitor *visitor) { visitor->Visit(this); }
void GameCubeMeshComponents::Accept(GameComponentVisitor *visitor) { visitor->Visit(this); }
void GameLocationsComponents::Accept(GameComponentVisitor *visitor) { visitor->Visit(this); }
void GamePropertiesComponents::Accept(GameComponentVisitor *visitor) { visitor->Visit(this); }
void GameBoxCollisionComponents::Accept(GameComponentVisitor *visitor) { visitor->Visit(this); }
void GameTerrainColliderComponents::Accept(GameComponentVisitor *visitor) { visitor->Visit(this); }
void GameSwitchComponents::Accept(GameComponentVisitor *visitor) { visitor->Visit(this); }
