#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Scene.h"
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

		void CreateLevelBackground();
		void UpdateLevelBackground();

	
		void CreatePipes();
		void SpawnPipes(sf::Vector2f pos, PlayerEntity* pl);
		void UpdatePipes();



	};
}

