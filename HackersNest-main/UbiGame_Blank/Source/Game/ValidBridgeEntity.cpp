#include "ValidBridgeEntity.h"

using namespace Game;

ValidBridgeEntity::ValidBridgeEntity()
{
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::ValidBridge);
	m_renderComponent->SetZLevel(3);

}

ValidBridgeEntity::~ValidBridgeEntity()
{
}

void ValidBridgeEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}

void ValidBridgeEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();

}
