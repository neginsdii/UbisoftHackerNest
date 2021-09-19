#include "BridgeEntity.h"

using namespace Game;

BridgeEntity::BridgeEntity()
{
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::Bridge);
	m_renderComponent->SetZLevel(3);

	AddComponent<GameEngine::CollidableComponent>();
	GetComponent<GameEngine::CollidableComponent>()->SetBoundingBox(sf::Vector2f(96.f, 10.f));


	SetEntityTag("Platform");

}

BridgeEntity::~BridgeEntity()
{
}

void BridgeEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}

void BridgeEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();

}
