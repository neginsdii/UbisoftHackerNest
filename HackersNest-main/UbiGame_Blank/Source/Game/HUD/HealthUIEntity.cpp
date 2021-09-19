#include "HealthUIEntity.h"

using namespace Game;

HealthUIEntity::HealthUIEntity()
{
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::Heart);
	m_renderComponent->SetZLevel(3);

}

HealthUIEntity::~HealthUIEntity()
{
}

void HealthUIEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}

void HealthUIEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();

}
