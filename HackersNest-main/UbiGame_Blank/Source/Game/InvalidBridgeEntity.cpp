#include "InvalidBridgeEntity.h"

using namespace Game;

InvalidBridgeEntity::InvalidBridgeEntity()
{
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::InvalidBridge);
	m_renderComponent->SetZLevel(3);

}

InvalidBridgeEntity::~InvalidBridgeEntity()
{
}

void InvalidBridgeEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}

void InvalidBridgeEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();

}
