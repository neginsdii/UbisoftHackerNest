#include "PlayerEntity.h"
using namespace Game;

PlayerEntity::PlayerEntity()
{
	m_playerMovement = AddComponent<PlayerMovement>();

	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::Player);
	m_renderComponent->SetZLevel(3);

	m_animationComponent = AddComponent<GameEngine::AnimationComponent>();

	AddComponent<GameEngine::CollidablePhysicsComponent>();

}

PlayerEntity::~PlayerEntity()
{
}

void PlayerEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();

	if (m_animationComponent)
	{
		m_animationComponent->PlayAnim(GameEngine::EAnimationId::PlayerWalk);
	}
}

void PlayerEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}
