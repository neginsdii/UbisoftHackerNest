#include "TrapEntity.h"

using namespace Game;

TrapEntity::TrapEntity()
{
	
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::Trap);
	m_renderComponent->SetZLevel(3);

	AddComponent<GameEngine::CollidableComponent>();
	GetComponent<GameEngine::CollidableComponent>()->SetBoundingBox(sf::Vector2f(36.f, 51.f));

	SetEntityTag("Trap");

}

TrapEntity::~TrapEntity()
{
}

void TrapEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}

void TrapEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();

}
