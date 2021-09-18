#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Scene.h"
#include "Game/MenuBGEntity.h"
#include "Game/PlayerEntity.h"
#include "Game/PlatformEntity.h"

#include <SFML/System/Vector2.hpp>
#include <vector>
namespace Game
{
	class MenuScene : public GameEngine::Scene
	{
	public:
		MenuScene();
		virtual ~MenuScene();

		virtual void Start() override;
		virtual void Update() override;
		virtual void Clean() override;

	private:
		MenuBGEntity* m_menuBG;
		PlayerEntity* m_Player;
		PlatformEntity* m_platform;

	};
}