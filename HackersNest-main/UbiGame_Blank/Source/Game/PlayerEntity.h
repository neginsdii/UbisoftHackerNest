#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

namespace Game
{

	class PlayerEntity : public GameEngine::Entity
	{
	public:
		PlayerEntity();
		~PlayerEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

	private:

		GameEngine::SpriteRenderComponent* m_renderComponent;
		GameEngine::AnimationComponent* m_animationComponent;

	};
}