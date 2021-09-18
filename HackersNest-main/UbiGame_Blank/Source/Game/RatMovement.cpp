#include "RatMovement.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"

#include "GameEngine/Util/TextureManager.h"
#include "GameEngine/Util/AnimationManager.h"
#include <iostream>
#include <SFML/Window/Keyboard.hpp>

using namespace Game;

RatMovement::RatMovement()
	: m_animComponent(nullptr)
	, m_renderComponent(nullptr)
	, isRunning(false)
	, m_ratSpeed(120.0f)
	, m_ratValocity(0.0f, 0.0f)
	, m_gravity(9.8f)
	, m_direction(1.0f, 1.0f)
{
}

RatMovement::~RatMovement()
{
}

void RatMovement::Update()
{
	Component::Update();
	float dt = GameEngine::GameEngineMain::GetTimeDelta();

	m_ratValocity.x = m_ratSpeed * dt;
	GetEntity()->SetPos(GetEntity()->GetPos() - m_ratValocity);


}

void RatMovement::OnAddToWorld()
{
	m_animComponent = GetEntity()->GetComponent<GameEngine::AnimationComponent>();
	m_renderComponent = GetEntity()->GetComponent<GameEngine::SpriteRenderComponent>();

}
