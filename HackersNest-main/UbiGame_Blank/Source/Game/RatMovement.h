#pragma once
#include <vector>
#include "GameEngine/EntitySystem/Component.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

namespace Game
{
	class RatMovement : public GameEngine::Component
	{
	public:

		RatMovement();
		~RatMovement();

		virtual void Update() override;
		virtual void OnAddToWorld() override;

		void SetRatSpeed(float fspeed) { m_ratSpeed = fspeed; }

	private:
		GameEngine::SpriteRenderComponent* m_renderComponent;
		GameEngine::AnimationComponent* m_animComponent;

		bool isRunning;

		float m_gravity;
		float m_ratSpeed;
		sf::Vector2f m_ratValocity;
		sf::Vector2f m_direction;

	};
}