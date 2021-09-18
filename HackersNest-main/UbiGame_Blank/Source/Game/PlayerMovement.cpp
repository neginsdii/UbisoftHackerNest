#include "PlayerMovement.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

#include "GameEngine/Util/TextureManager.h"
#include "GameEngine/Util/AnimationManager.h"
#include <iostream>
#include <SFML/Window/Keyboard.hpp>
using namespace Game;

PlayerMovement::PlayerMovement()
	: m_animComponent(nullptr)
	, m_renderComponent(nullptr)
	, isRunning(false)
	, isJumping(true)
	, m_playerSpeed(30.0f)
	, m_playerValocity(0.0f, 0.0f)
	, m_gravity(9.8f)
	, m_direction(1.0f, 1.0f)
	, m_jumpTime(0.0f)
	, m_maxJumpTime(0.15f)
{
}

PlayerMovement::~PlayerMovement()
{
}

void PlayerMovement::Update()
{
	Component::Update();
	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	Jump();
	if (isJumping)
	{
		m_playerValocity.y = m_gravity * dt * 25.0f;

	}
	else
	{
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && GetEntity()->GetEntityTag() == "SecondPlayer")
			|| ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) && GetEntity()->GetEntityTag() == "FirstPlayer"))) {
			m_playerValocity.x = m_playerSpeed * dt;
			m_renderComponent->SetScale(sf::Vector2f(abs( m_renderComponent->GetScale().x),  m_renderComponent->GetScale().y));


		}
		else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && GetEntity()->GetEntityTag() == "SecondPlayer")
			|| ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) && GetEntity()->GetEntityTag() == "FirstPlayer"))) {
			m_playerValocity.x = -1 * m_playerSpeed * dt;
			m_renderComponent->SetScale(sf::Vector2f(abs(m_renderComponent->GetScale().x)*-1, m_renderComponent->GetScale().y));

		}
		else
			m_playerValocity.x = 0.0f;
	}
	GetEntity()->SetPos(GetEntity()->GetPos() + m_playerValocity);
	if (m_animComponent)
	{
		if (isRunning)
		{
		 if (m_playerValocity.x == 0)
		{
			if (m_animComponent->GetCurrentAnimation() != GameEngine::EAnimationId::PlayerIdle)
			{
				m_animComponent->PlayAnim(GameEngine::EAnimationId::PlayerIdle);
			}
		}
		 else {
			 if (m_animComponent->GetCurrentAnimation() != GameEngine::EAnimationId::PlayerWalk)
			 {
				 m_animComponent->PlayAnim(GameEngine::EAnimationId::PlayerWalk);
			 }
		 }

		}
		else if (isJumping)
		{
			if (m_animComponent->GetCurrentAnimation() != GameEngine::EAnimationId::PlayerJump)
			{
				m_animComponent->PlayAnim(GameEngine::EAnimationId::PlayerJump);
			}
		}
		else if(m_playerValocity.x==0)
		{
			if (m_animComponent->GetCurrentAnimation() != GameEngine::EAnimationId::PlayerIdle)
			{
				m_animComponent->PlayAnim(GameEngine::EAnimationId::PlayerIdle);
			}
		}
	}
}

void PlayerMovement::OnAddToWorld()
{
	m_animComponent = GetEntity()->GetComponent<GameEngine::AnimationComponent>();
	m_renderComponent = GetEntity()->GetComponent<GameEngine::SpriteRenderComponent>();

}

void PlayerMovement::Jump()
{
	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	if (GetEntity()->GetComponent<GameEngine::CollidablePhysicsComponent>()->CheckCollision()) {
		//	m_playerValocity.y = 0.0f;
		if (isJumping)
		{
			m_jumpTime += dt;
			if (m_jumpTime >= m_maxJumpTime) {
				isJumping = false;
				m_jumpTime = 0.0f;
			}
		}
		isRunning = true;
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && GetEntity()->GetEntityTag() == "SecondPlayer")
			|| ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) && GetEntity()->GetEntityTag() == "FirstPlayer"))) {
			if (!isJumping) {
				m_gravity *= -1;
				m_renderComponent->SetScale(sf::Vector2f(m_renderComponent->GetScale().x,-1*m_renderComponent->GetScale().y));
				isJumping = true;
				isRunning = false;
			}
		}


	}
}
