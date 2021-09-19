#include "BoxEntity.h"

using namespace Game;

BoxEntity::BoxEntity()
{
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::Box);
	m_renderComponent->SetZLevel(3);

}

BoxEntity::~BoxEntity()
{
}

void BoxEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}

void BoxEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();

}
