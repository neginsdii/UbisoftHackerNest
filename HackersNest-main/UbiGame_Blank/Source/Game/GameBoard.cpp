#include "GameBoard.h"
#include "GameEngine/GameEngineMain.h"
#include <time.h> 
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
using namespace Game;
int GameBoard::m_numOfBridges = 2;

GameBoard::GameBoard()
	:m_firstPlayer(nullptr)
	, m_secondPlayer(nullptr)
	,m_invalidBridge(nullptr)
	,m_validBridge(nullptr)
	
{
	CreateLevelBackground();
	
	m_firstPlayer = new PlayerEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_firstPlayer);
	m_firstPlayer->SetPos(sf::Vector2f(100.0f, 240.0f));
	m_firstPlayer->SetSize(TextureHelper::GetTextureTileSize(GameEngine::eTexture::Player) * 3.0f);
	m_firstPlayer->SetEntityTag("FirstPlayer");

	m_secondPlayer = new PlayerEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_secondPlayer);
	m_secondPlayer->SetPos(sf::Vector2f(100.0f, 650.0f));
	m_secondPlayer->SetSize(TextureHelper::GetTextureTileSize(GameEngine::eTexture::Player) * 3.0f);
	m_secondPlayer->SetEntityTag("SecondPlayer");

	
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
	SpawnRats();
	UpdateBridges();
}

void GameBoard::Clean()
{
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_firstPlayer);
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_secondPlayer);
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_firstPlayerBG);
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_secondPlayerBG);
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_firstFloor);
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_SecondFloor);

}

void GameBoard::CreateLevelBackground()
{
	m_firstPlayerBG = new GameBGEntity();
	m_firstPlayerBG->SetPos(sf::Vector2f(  GameEngine::GameEngineMain::GetInstance()->GetWindowWidth() / 2.0f, GameEngine::GameEngineMain::GetInstance()->GetWindowHeight() / 5.0f));
	m_firstPlayerBG->GetComponent<GameEngine::SpriteRenderComponent>()->SetTexture(GameEngine::eTexture::BGGame);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_firstPlayerBG);

	m_secondPlayerBG = new GameBGEntity();
	m_secondPlayerBG->SetPos(sf::Vector2f( GameEngine::GameEngineMain::GetInstance()->GetWindowWidth() / 2.0f, GameEngine::GameEngineMain::GetInstance()->GetWindowHeight() / 3.0f + 290.0f));
	m_secondPlayerBG->GetComponent<GameEngine::SpriteRenderComponent>()->SetTexture(GameEngine::eTexture::BGGame2);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_secondPlayerBG);

	m_firstFloor= new PlatformEntity();
	m_firstFloor->SetPos(sf::Vector2f( GameEngine::GameEngineMain::GetInstance()->GetWindowWidth() / 2.0f, GameEngine::GameEngineMain::GetInstance()->GetWindowHeight() / 2.0f - 90.0f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_firstFloor);

	/*m_SecondFloor = new PlatformEntity();
	m_SecondFloor->SetPos(sf::Vector2f( GameEngine::GameEngineMain::GetInstance()->GetWindowWidth() / 2.0f, 5 * GameEngine::GameEngineMain::GetInstance()->GetWindowHeight() / 6.0f + 20.0f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_SecondFloor);*/

	m_secondSewage = new SewageEntity();
	m_secondSewage->SetPos(sf::Vector2f(GameEngine::GameEngineMain::GetInstance()->GetWindowWidth() / 2.0f, GameEngine::GameEngineMain::GetInstance()->GetWindowHeight() / 3.0f + 290.0f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_secondSewage);

	BridgeEntity* brg = new BridgeEntity();
	brg->SetPos((sf::Vector2f(GameEngine::GameEngineMain::GetInstance()->GetWindowWidth() / 13.0f, 5 * GameEngine::GameEngineMain::GetInstance()->GetWindowHeight() / 6.0f + 20.0f)));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(brg);
	m_vBridges.push_back(brg);

}




void GameBoard::CreatePipes()
{

	sf::Vector2f size = sf::Vector2f(288.f, 72.f);

	for (int i = 0; i < 8; i++)
	{
		PipeEntity* pipe = new PipeEntity();
		GameEngine::GameEngineMain::GetInstance()->AddEntity(pipe);
		pipe->SetPos(sf::Vector2f(size.x / 2 + i * size.x, 25.0f));
		pipe->SetSize(sf::Vector2f(size.x, size.y));
		m_firstPipes.push_back(pipe);

		PipeEntity* pipe1 = new PipeEntity();
		GameEngine::GameEngineMain::GetInstance()->AddEntity(pipe1);
		pipe1->SetPos(sf::Vector2f(size.x / 2 + i * size.x, 423.0f));
		pipe1->SetSize(sf::Vector2f(size.x, size.y));
		m_secondPipes.push_back(pipe1);
	}
}

void GameBoard::SpawnRats()
{
	float dt = GameEngine::GameEngineMain::GetTimeDelta();
	srand(time(NULL));

	m_ratRespawnTime += dt;
	if (m_ratRespawnTime >= m_maxRatRespawnTime)
	{
		int rnd = rand() % 2;
		float ratSpeed = rand() % 60 + 120;
		if (rnd == 1)
		{
			RatEntity* tmpRat = new RatEntity();
			tmpRat->SetPos(sf::Vector2f(1700.0f, 280.0f));
			tmpRat->SetSize(TextureHelper::GetTextureTileSize(GameEngine::eTexture::Rat));
			tmpRat->SetEntityTag("Rat");
			tmpRat->GetComponent<RatMovement>()->SetRatSpeed(ratSpeed);
			GameEngine::GameEngineMain::GetInstance()->AddEntity(tmpRat);
			m_vFirstRats.push_back(tmpRat);

		}
		else
		{
			RatEntity* tmpRat = new RatEntity();
			tmpRat->SetPos(sf::Vector2f(1700.0f, 90.0f));
			tmpRat->SetSize(TextureHelper::GetTextureTileSize(GameEngine::eTexture::Rat));
			tmpRat->SetEntityTag("Rat");
			tmpRat->GetComponent<RatMovement>()->SetRatSpeed(ratSpeed);
			GameEngine::GameEngineMain::GetInstance()->AddEntity(tmpRat);
			m_vFirstRats.push_back(tmpRat);

		}
		m_ratRespawnTime = 0.0f;
		m_maxRatRespawnTime = rand() % 4 + 3;
	}
	UpdateRats();
}

void GameBoard::UpdateRats()
{
	for (std::vector<RatEntity*>::iterator it = m_vFirstRats.begin(); it != m_vFirstRats.end();)
	{
		RatEntity* rat = (*it);
		sf::Vector2f currPos = rat->GetPos();
		if (currPos.x < -300.f)
		{
			GameEngine::GameEngineMain::GetInstance()->RemoveEntity(rat);
			it = m_vFirstRats.erase(it);
		}
		else
		{
			it++;

		}
	}

}

void GameBoard::UpdateBridges()
{
	sf::Vector2f size = sf::Vector2f(96.f, 27.f);
	
	auto tmp = m_vBridges.back();
	sf::Vector2f posBrg = m_vBridges.back()->GetPos();
	if ((  posBrg.x- m_secondPlayer->GetPos().x) < 10.0f)
	{
			if (m_numOfBridges > 0) {
				if (m_invalidBridge) {
					GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_invalidBridge);
					m_invalidBridge = nullptr;
				}
				if (!m_validBridge) {
					
					m_validBridge = new ValidBridgeEntity();
					m_validBridge->SetPos((sf::Vector2f(m_vBridges.back()->GetPos().x + size.x, 5 * GameEngine::GameEngineMain::GetInstance()->GetWindowHeight() / 6.0f + 20.0f)));
					GameEngine::GameEngineMain::GetInstance()->AddEntity(m_validBridge);
				}
			}
			else {
				if (!m_invalidBridge) {
					m_invalidBridge = new InvalidBridgeEntity();
					m_invalidBridge->SetPos((sf::Vector2f(m_vBridges.back()->GetPos().x + size.x, 5 * GameEngine::GameEngineMain::GetInstance()->GetWindowHeight() / 6.0f + 20.0f)));
					GameEngine::GameEngineMain::GetInstance()->AddEntity(m_invalidBridge);
				}
			}
				
			if (m_validBridge)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_secondPlayer->GetEntityTag() == "SecondPlayer")
				{
					BridgeEntity* brg = new BridgeEntity();
					brg->SetPos(m_validBridge->GetPos());
					GameEngine::GameEngineMain::GetInstance()->AddEntity(brg);
					m_vBridges.push_back(brg);
					m_numOfBridges--;
					GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_validBridge);
					m_validBridge = nullptr;

				}
			}
	}

}
