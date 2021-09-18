#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Scene.h"
#include "Game/PlayerEntity.h"
#include "Game/PlatformEntity.h"
#include "Game/GameBGEntity.h"
#include "Game/PipeEntity.h"
#include "Game/RatEntity.h"
#include "Game/SewageEntity.h"
#include <SFML/System/Vector2.hpp>
#include <vector>
namespace Game
{
	//Used for storing and controlling all game related entities, as well as providing an entry point for the "game" side of application	
	class PlayerEntity;

	class GameBoard : public GameEngine::Scene
	{
	public:
		GameBoard();
		virtual ~GameBoard();

		virtual void Start() override;
		virtual void Update() override;
		virtual void Clean() override;
		bool IsGameOver() { return false; }

	private:

		PlayerEntity* m_firstPlayer;
		PlayerEntity* m_secondPlayer;

		PlatformEntity* m_firstFloor;
		PlatformEntity* m_SecondFloor;

		GameBGEntity* m_firstPlayerBG;
		GameBGEntity* m_secondPlayerBG;
		SewageEntity* m_secondSewage;

		void CreateLevelBackground();
	
		void CreatePipes();
		std::vector<GameEngine::Entity*> m_firstPipes;
		std::vector<GameEngine::Entity*> m_secondPipes;

		float m_ratRespawnTime;
		float m_maxRatRespawnTime;

		void SpawnRats();
		void UpdateRats();
		std::vector<RatEntity*> m_vFirstRats;


	};
}

