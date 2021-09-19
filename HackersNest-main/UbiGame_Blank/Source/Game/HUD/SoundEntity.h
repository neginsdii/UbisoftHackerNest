#pragma once

#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SoundComponent.h"

class SoundEntity : public GameEngine::Entity
{
public:
	SoundEntity();
	~SoundEntity();

	virtual void OnAddToWorld() override;
	virtual void OnRemoveFromWorld() override;

private:
	GameEngine::SoundComponent* m_soundComponent;

};