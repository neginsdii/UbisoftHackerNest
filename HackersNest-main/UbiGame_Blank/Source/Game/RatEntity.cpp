#include "RatEntity.h"
using namespace Game;


RatEntity::RatEntity()
{
	m_ratMovement = AddComponent<RatMovement>();

	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::Rat);
	m_renderComponent->SetZLevel(4);

	m_animationComponent = AddComponent<GameEngine::AnimationComponent>();

	AddComponent<GameEngine::CollidablePhysicsComponent>();
//	GetComponent<GameEngine::CollidablePhysicsComponent>()->setCollisionTag(GameEngine::collisionTag::RatCTag);
	SetEntityTag("Rat");
}

RatEntity::~RatEntity()
{
}

void RatEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();

	if (m_animationComponent)
	{
		m_animationComponent->PlayAnim(GameEngine::EAnimationId::Rat);
	}
}

void RatEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();

}
