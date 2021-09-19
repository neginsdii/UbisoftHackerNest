#include "InvalidTrapEntity.h"

using namespace Game;

InvalidTrapEntity::InvalidTrapEntity()
{
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::InvalidTrap);
	m_renderComponent->SetZLevel(3);

}

InvalidTrapEntity::~InvalidTrapEntity()
{
}

void InvalidTrapEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}

void InvalidTrapEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();

}
