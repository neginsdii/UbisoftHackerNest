#include "GameBoard.h"
#include "GameEngine/GameEngineMain.h"
#include <time.h> 

using namespace Game;

GameBoard::GameBoard()
	:m_firstPlayer(nullptr)
	, m_secondPlayer(nullptr)
	
{
	CreateLevelBackground();

	
	CreatePipes();
}


GameBoard::~GameBoard()
{

}

void GameBoard::Start()
{
}

void GameBoard::Update()
{
	UpdateLevelBackground();
	UpdatePipes();
}

void GameBoard::Clean()
{
	
}

void GameBoard::CreateLevelBackground()
{
	for (int i = 0; i < 2; i++)
	{
	
	}
}


void GameBoard::UpdateLevelBackground()
{
	for (int i = 0; i < 2; i++)
	{
		
	}
}

void GameBoard::CreatePipes()
{

	sf::Vector2f size = sf::Vector2f(288.f, 72.f);

	for (int i = 0; i < 8; i++)
	{
	
	}
}

void GameBoard::SpawnPipes(sf::Vector2f pos, PlayerEntity* pl)
{
	

}

void GameBoard::UpdatePipes()
{
	
}
