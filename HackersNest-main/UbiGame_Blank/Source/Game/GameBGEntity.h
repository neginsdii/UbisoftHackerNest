#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

namespace Game
{
	class GameBGEntity : public GameEngine::Entity
	{
	public:
		GameBGEntity();
		~GameBGEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;
		

	private:

		GameEngine::SpriteRenderComponent* m_renderComponent;
	
	};
}