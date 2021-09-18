#pragma once
#include <vector>
#include "GameEngine/EntitySystem/Component.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

namespace Game
{
	class PlayerMovement : public GameEngine::Component
	{
	public:

		PlayerMovement();
		~PlayerMovement();

		virtual void Update() override;
		virtual void OnAddToWorld() override;
		void Jump();
	private:
		GameEngine::SpriteRenderComponent* m_renderComponent;
		GameEngine::AnimationComponent* m_animComponent;

		bool isRunning;
		bool isJumping;

		float m_gravity;
		float m_playerSpeed;
		float m_jumpTime;
		float m_maxJumpTime;
		sf::Vector2f m_playerValocity;
		sf::Vector2f m_direction;

	};
}