#pragma once
#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "Game/RatMovement.h"


namespace Game
{

	class RatEntity : public GameEngine::Entity
	{
	public:
		RatEntity();
		~RatEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

	private:

		GameEngine::SpriteRenderComponent* m_renderComponent;
		GameEngine::AnimationComponent* m_animationComponent;
		RatMovement* m_ratMovement;

	};
}