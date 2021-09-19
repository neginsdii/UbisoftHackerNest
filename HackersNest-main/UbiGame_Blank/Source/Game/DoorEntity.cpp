#include "DoorEntity.h"
using namespace Game;
DoorEntity::DoorEntity()
{
	m_renderComponent = AddComponent<GameEngine::RenderComponent>();
	m_renderComponent->SetZLevel(2);
	AddComponent<GameEngine::CollidableComponent>();
	GetComponent<GameEngine::CollidableComponent>()->SetBoundingBox(sf::Vector2f(78.0f, 143.0f));
	SetEntityTag("Door");
}

DoorEntity::~DoorEntity()
{
}

void DoorEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();

}

void DoorEntity::OnRemoveFromWorld()
{
	Entity::OnAddToWorld();

}