#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Scene.h"
#include "Game/PlayerEntity.h"
#include "Game/PlatformEntity.h"
#include "Game/GameBGEntity.h"
#include "Game/PipeEntity.h"
#include "Game/RatEntity.h"
#include "Game/SewageEntity.h"
#include "Game/Bridges/BridgeEntity.h"
#include "Game/Bridges/InvalidBridgeEntity.h"
#include "Game/Bridges/ValidBridgeEntity.h"
#include "Game/Traps/TrapEntity.h"
#include "Game/Traps/ValidTrapEntity.h"
#include "Game/Traps/InvalidTrapEntity.h"
#include "Game/HUD/HUDEntity.h"
#include "Game/HUD/HealthUIEntity.h"
#include "Game/HUD/WoodEntity.h"
#include "Game/HUD/BoxEntity.h"
#include "Game/HUD/SoundEntity.h"
#include "Game/DoorEntity.h"
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

		sf::Vector2f m_spawnPosFirstPlayer;
		sf::Vector2f m_spawnPosSecondPlayer;

		void UpdatePlayers();

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

		std::vector<BridgeEntity*> m_vBridges;
		static int m_numOfBridges;
		void UpdateBridges();
		InvalidBridgeEntity* m_invalidBridge;
		ValidBridgeEntity* m_validBridge;

		static int ms_levelTraps;
		static int m_numOfTraps;
		std::vector<TrapEntity*> m_vTraps;
		std::vector<sf::Vector2f> m_vTrapsPoses;
		InvalidTrapEntity* m_invalidTrap;
		ValidTrapEntity* m_validTrap;
		void InitPoses();
		void UpdateTraps();
		sf::Vector2f FindClosetTrapLocation();
		bool IsTrapSet(sf::Vector2f point);

		HUDEntity* m_hud;
		WoodEntity* m_wood;
		BoxEntity* m_box;
		std::vector<HealthUIEntity*> m_firstPlayerHealth;
		std::vector<HealthUIEntity*> m_secondPlayerHealth;
		void CreateHealthUI();

		static int ms_numOfBoxes;
		static int ms_numOfWoods;

		SoundEntity* m_sound;

		DoorEntity* m_door;
	};
}

