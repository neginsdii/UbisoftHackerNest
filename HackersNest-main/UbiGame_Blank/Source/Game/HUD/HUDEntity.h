
#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"

namespace Game
{
	class HUDEntity : public GameEngine::Entity
	{
	public:
		HUDEntity();
		~HUDEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

		void SetText(int txt, int wood);
	private:

		GameEngine::TextRenderComponent* m_textRendererComponent;
		
	};
}
