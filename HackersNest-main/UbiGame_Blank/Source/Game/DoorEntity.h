#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/RenderComponent.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"

namespace Game
{
	class DoorEntity : public GameEngine::Entity
	{
	public:
		DoorEntity();
		~DoorEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

	private:
		GameEngine::RenderComponent* m_renderComponent;
	};
}