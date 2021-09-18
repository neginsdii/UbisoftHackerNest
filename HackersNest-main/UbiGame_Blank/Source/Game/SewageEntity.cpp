#include "Game/SewageEntity.h"
using namespace Game;

SewageEntity::SewageEntity()
{
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::Sewage);
	m_renderComponent->SetZLevel(2);


	m_animationComponent = AddComponent<GameEngine::AnimationComponent>();

	//AddComponent<GameEngine::CollidableComponent>();
	SetEntityTag("Sewage");
}

SewageEntity::~SewageEntity()
{
}

void SewageEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();

	if (m_animationComponent)
	{
		m_animationComponent->PlayAnim(GameEngine::EAnimationId::Sewage);
	}
}

void SewageEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}
