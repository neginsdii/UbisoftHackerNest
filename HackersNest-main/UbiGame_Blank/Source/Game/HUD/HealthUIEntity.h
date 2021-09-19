#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"


namespace Game
{
	class HealthUIEntity : public GameEngine::Entity
	{
	public:
		HealthUIEntity();
		~HealthUIEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

	private:

		GameEngine::SpriteRenderComponent* m_renderComponent;

	};
}