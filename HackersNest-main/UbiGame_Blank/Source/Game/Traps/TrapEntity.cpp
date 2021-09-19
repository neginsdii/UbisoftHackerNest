#include "TrapEntity.h"

using namespace Game;

TrapEntity::TrapEntity()
{
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::Trap);
	m_renderComponent->SetZLevel(3);

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
