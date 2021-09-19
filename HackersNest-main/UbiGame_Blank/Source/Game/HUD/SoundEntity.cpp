#include "SoundEntity.h"

SoundEntity::SoundEntity()
{
	m_soundComponent = AddComponent<GameEngine::SoundComponent>();

	m_soundComponent->PlaySound(m_soundComponent->LoadSoundFromFile("Resources/snd/bg.ogg"), false);
}

SoundEntity::~SoundEntity()
{
}

void SoundEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}

void SoundEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}