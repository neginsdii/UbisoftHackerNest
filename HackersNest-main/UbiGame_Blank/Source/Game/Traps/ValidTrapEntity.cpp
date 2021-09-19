#include "ValidTrapEntity.h"

using namespace Game;

ValidTrapEntity::ValidTrapEntity()
{
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::ValidTrap);
	m_renderComponent->SetZLevel(3);

}

ValidTrapEntity::~ValidTrapEntity()
{
}

void ValidTrapEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}

void ValidTrapEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();

}
