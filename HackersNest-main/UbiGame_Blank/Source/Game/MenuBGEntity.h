#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

namespace Game {
	class MenuBGEntity : public GameEngine::Entity
	{
	public:
		MenuBGEntity();
		~MenuBGEntity();


		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;


	private:

		GameEngine::SpriteRenderComponent* m_renderComponent;
	};
}