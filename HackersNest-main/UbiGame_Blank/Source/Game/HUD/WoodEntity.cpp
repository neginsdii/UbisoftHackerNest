#include "WoodEntity.h"

using namespace Game;

WoodEntity::WoodEntity()
{
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::Wood);
	m_renderComponent->SetZLevel(3);

}

WoodEntity::~WoodEntity()
{
}

void WoodEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}

void WoodEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();

}
