#include "PlatformEntity.h"
using namespace Game;
PlatformEntity::PlatformEntity()
{
	m_renderComponent = AddComponent<GameEngine::RenderComponent>();
	m_renderComponent->SetZLevel(2);
	AddComponent<GameEngine::CollidableComponent>();
	GetComponent<GameEngine::CollidableComponent>()->SetBoundingBox(sf::Vector2f(1609.0f, 20.0f));
	SetEntityTag("Platform");
}

PlatformEntity::~PlatformEntity()
{
}

void PlatformEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();

}

void PlatformEntity::OnRemoveFromWorld()
{
	Entity::OnAddToWorld();

}