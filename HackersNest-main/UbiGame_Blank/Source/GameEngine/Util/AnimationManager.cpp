#include "AnimationManager.h"


using namespace GameEngine;

AnimationManager* AnimationManager::sm_instance = nullptr;

AnimationManager::AnimationManager()
{

}


AnimationManager::~AnimationManager()
{

}


void AnimationManager::InitStaticGameAnimations()
{
	m_animDefinitions.push_back
	(
		SAnimationDefinition(
			EAnimationId::PlayerIdle,
			eTexture::Player,
			sf::Vector2i(0, 5),
			4,
		4)
	);

	m_animDefinitions.push_back
	(
		SAnimationDefinition(
			EAnimationId::PlayerWalk,
			eTexture::Player,
			sf::Vector2i(0, 0),
			8,
			6)
	);

	m_animDefinitions.push_back
	(
		SAnimationDefinition(
			EAnimationId::PlayerAttack,
			eTexture::Player,
			sf::Vector2i(0, 2),
			8,
			15)
	);

	m_animDefinitions.push_back
	(
		SAnimationDefinition(
			EAnimationId::PlayerDie,
			eTexture::Player,
			sf::Vector2i(0, 4),
			9,
			15)
	);
	m_animDefinitions.push_back
	(
		SAnimationDefinition(
			EAnimationId::PlayerJump,
			eTexture::Player,
			sf::Vector2i(0, 3),
			6,
			3)
	);


	m_animDefinitions.push_back
	(
		SAnimationDefinition(
			EAnimationId::Sewage,
			eTexture::Sewage,
			sf::Vector2i(0, 0),
			9,
			4)
	);

	m_animDefinitions.push_back
	(
		SAnimationDefinition(
			EAnimationId::Rat,
			eTexture::Rat,
			sf::Vector2i(0, 0),
			3,
			6)
	);
}


void AnimationManager::ReleaseStaticGameAnimations()
{
	m_animDefinitions.clear();
}


const SAnimationDefinition* AnimationManager::GetAnimDefinition(EAnimationId::type animId) const
{
	for (int a = 0; a < m_animDefinitions.size(); ++a)
	{
		if (m_animDefinitions[a].m_animId == animId)
			return &m_animDefinitions[a];
	}

	return nullptr;
}
