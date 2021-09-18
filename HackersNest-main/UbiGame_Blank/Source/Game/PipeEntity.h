#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"

namespace Game
{
	class PipeEntity : public GameEngine::Entity
	{
	public:
		PipeEntity();
		~PipeEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

	private:

		GameEngine::SpriteRenderComponent* m_renderComponent;
		GameEngine::AnimationComponent* m_animationComponent;

	};
}
