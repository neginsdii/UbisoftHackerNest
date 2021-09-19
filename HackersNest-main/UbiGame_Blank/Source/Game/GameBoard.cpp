#include "GameBoard.h"
#include "GameEngine/GameEngineMain.h"
#include <time.h> 
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
using namespace Game;
int GameBoard::m_numOfBridges = 0;
int GameBoard::m_numOfTraps = 0;
int GameBoard::ms_levelTraps = 8;
int GameBoard::ms_numOfBoxes=0;
int GameBoard::ms_numOfWoods=0;
GameBoard::GameBoard()
	:m_firstPlayer(nullptr)
	, m_secondPlayer(nullptr)
	,m_invalidBridge(nullptr)
	,m_validBridge(nullptr)
	,m_hud(nullptr)
	,m_wood(nullptr)
	,m_box(nullptr)
	,m_sound(nullptr)

{
	CreateLevelBackground();
	
	m_firstPlayer = new PlayerEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_firstPlayer);
	m_firstPlayer->SetPos(sf::Vector2f(100.0f, 240.0f));
	m_spawnPosFirstPlayer = sf::Vector2f(100.0f, 240.0f);
	m_firstPlayer->SetSize(TextureHelper::GetTextureTileSize(GameEngine::eTexture::Player) * 3.0f);
	m_firstPlayer->SetEntityTag("FirstPlayer");

	m_secondPlayer = new PlayerEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_secondPlayer);
	m_secondPlayer->SetPos(sf::Vector2f(100.0f, 650.0f));
	m_spawnPosSecondPlayer =sf::Vector2f(100.0f, 650.0f);
	m_secondPlayer->SetSize(TextureHelper::GetTextureTileSize(GameEngine::eTexture::Player) * 3.0f);
	m_secondPlayer->SetEntityTag("SecondPlayer");
	

	m_sound = new SoundEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_sound);
	InitPoses();
	
	CreatePipes();
	CreateHealthUI();

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
	UpdateTraps();
	UpdatePlayers();
	if (ms_numOfWoods / 4 > 0) {
		m_numOfBridges += ms_numOfWoods / 4;
		ms_numOfWoods -= (ms_numOfWoods/4);
	}
	m_hud->SetText(m_numOfBridges, ms_numOfWoods);
}

void GameBoard::Clean()
{
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_firstPlayer);
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_secondPlayer);
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_firstPlayerBG);
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_secondPlayerBG);
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_firstFloor);
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_SecondFloor);
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_hud);

}

void GameBoard::UpdatePlayers()
{
	if (!m_firstPlayer->GetIsActive())
	{
		if (m_firstPlayer->GetHealth() > 0) {
			m_firstPlayer->SetHealth(m_firstPlayer->GetHealth() - 1);
			GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_firstPlayerHealth[m_firstPlayerHealth.size()-1]);
			m_firstPlayerHealth.pop_back();
			m_firstPlayer->SetPos(m_spawnPosFirstPlayer);
			m_firstPlayer->SetIsActive(true);
		}
		else
		{
			m_firstPlayer->SetPos(sf::Vector2f(-50.0f,100.0f));

		}
	}
	if (!m_secondPlayer->GetIsActive())
	{
		if (m_secondPlayer->GetHealth() >0) {
			m_secondPlayer->SetHealth(m_secondPlayer->GetHealth() - 1);
			GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_secondPlayerHealth[m_secondPlayerHealth.size() - 1]);
			m_secondPlayerHealth.pop_back();
			m_secondPlayer->SetPos(m_spawnPosSecondPlayer);
			m_secondPlayer->SetIsActive(true);

		}
		else
		{
			GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_secondPlayer);

		}
	}
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

	m_SecondFloor = new PlatformEntity();
	m_SecondFloor->SetPos(sf::Vector2f( GameEngine::GameEngineMain::GetInstance()->GetWindowWidth() / 2.0f, 5 * GameEngine::GameEngineMain::GetInstance()->GetWindowHeight() / 6.0f + 100.0f));
	m_SecondFloor->SetEntityTag("Sewage");
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_SecondFloor);

	m_secondSewage = new SewageEntity();
	m_secondSewage->SetPos(sf::Vector2f(GameEngine::GameEngineMain::GetInstance()->GetWindowWidth() / 2.0f, GameEngine::GameEngineMain::GetInstance()->GetWindowHeight() / 3.0f + 290.0f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_secondSewage);

	BridgeEntity* brg = new BridgeEntity();
	brg->SetPos((sf::Vector2f(GameEngine::GameEngineMain::GetInstance()->GetWindowWidth() / 13.0f, 5 * GameEngine::GameEngineMain::GetInstance()->GetWindowHeight() / 6.0f + 20.0f)));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(brg);
	m_vBridges.push_back(brg);


	/*TrapEntity* trp = new TrapEntity();
	trp->SetPos((sf::Vector2f(GameEngine::GameEngineMain::GetInstance()->GetWindowWidth() / 13.0f, 1 * GameEngine::GameEngineMain::GetInstance()->GetWindowHeight() / 6.0f + 20.0f)));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(trp);
	m_vTraps.push_back(trp);*/
	
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
			tmpRat->SetPos(sf::Vector2f(1700.0f, 260.0f));
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
		if (!rat->GetIsActive())
		{
			GameEngine::GameEngineMain::GetInstance()->RemoveEntity(rat);
			it = m_vFirstRats.erase(it);
			ms_numOfWoods++;
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
				
			if (m_validBridge )
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
	else
	{
		if (m_validBridge)
		{
			GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_validBridge);
			m_validBridge = nullptr;
		}
		if (m_invalidBridge)
		{
			GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_invalidBridge);
			m_invalidBridge = nullptr;
		}
	}

}

void GameBoard::InitPoses()
{
	for (int i = 0; i < 5; i++)
	{
		m_vTrapsPoses.push_back(sf::Vector2f(i * 350 + GameEngine::GameEngineMain::GetInstance()->GetWindowWidth() / 12.0f, 1 * GameEngine::GameEngineMain::GetInstance()->GetWindowHeight() /4.0f +45.0f));
	}
	for (int i = 0; i < 3; i++)
	{
		m_vTrapsPoses.push_back(sf::Vector2f(i * 350 + GameEngine::GameEngineMain::GetInstance()->GetWindowWidth() / 4.0f, 1 * GameEngine::GameEngineMain::GetInstance()->GetWindowHeight() / 8.0f ));
	}
}

sf::Vector2f GameBoard::FindClosetTrapLocation()
{
	sf::Vector2f closetPoint;
	float minVal = 5000.0f;
	for (int i = 0; i < ms_levelTraps; i++)
	{
		float dis = sqrt(pow((m_firstPlayer->GetPos().x - m_vTrapsPoses[i].x), 2) + pow((m_firstPlayer->GetPos().y - m_vTrapsPoses[i].y), 2));
		if (dis < minVal)
		{
			minVal=dis;
			closetPoint = m_vTrapsPoses[i];
		}
	}
	return closetPoint;
}

bool GameBoard::IsTrapSet(sf::Vector2f point)
{
	bool flg = false;
	
		for (int j = 0; j < m_vTraps.size(); j++)
		{
			if (m_vTraps[j]->GetPos() == point)
				flg = true;
		}

	return flg;
}

void GameBoard::CreateHealthUI()
{
	sf::Vector2f size = sf::Vector2f(27.f, 30.f);
	for (int i = 0; i < 3; i++)
	{
		HealthUIEntity* hlt = new HealthUIEntity();
		hlt->SetPos(sf::Vector2f(size.x*i+ 11*GameEngine::GameEngineMain::GetInstance()->GetWindowWidth()/12, 320.0f));
		GameEngine::GameEngineMain::GetInstance()->AddEntity(hlt);
		m_firstPlayerHealth.push_back(hlt);

		HealthUIEntity* hlt1 = new HealthUIEntity();
		hlt1->SetPos(sf::Vector2f(size.x * i +11 * GameEngine::GameEngineMain::GetInstance()->GetWindowWidth() / 12, 720.0f));
		GameEngine::GameEngineMain::GetInstance()->AddEntity(hlt1);
		m_secondPlayerHealth.push_back(hlt1);
	}

	m_hud = new HUDEntity();
	m_hud->SetPos(sf::Vector2(20.f, 320.f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_hud);

	

}

void GameBoard::UpdateTraps()
{
	
		sf::Vector2f closetPoint=FindClosetTrapLocation();
		float dis = sqrt(pow((m_firstPlayer->GetPos().x - closetPoint.x), 2) + pow((m_firstPlayer->GetPos().y - closetPoint.y), 2));
		if (dis < 50.0f)
		{
			if (m_numOfTraps <= ms_levelTraps)
			{
				if (m_invalidTrap) {
					GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_invalidTrap);
					m_invalidTrap = nullptr;
				}
				else if (!m_validTrap) {
					if (!IsTrapSet(closetPoint)) {
						m_validTrap = new ValidTrapEntity();
						m_validTrap->SetPos((sf::Vector2f(closetPoint.x, closetPoint.y)));
						GameEngine::GameEngineMain::GetInstance()->AddEntity(m_validTrap);
					}
				}
			}
			else
			{
				if (!m_invalidTrap) {
					m_invalidTrap = new InvalidTrapEntity();
					m_invalidTrap->SetPos((sf::Vector2f(closetPoint.x, closetPoint.y)));
					GameEngine::GameEngineMain::GetInstance()->AddEntity(m_invalidTrap);
				}
			}

			if (m_validTrap )
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && m_firstPlayer->GetEntityTag() == "FirstPlayer")
				{
					TrapEntity* trp = new TrapEntity();
					trp->SetPos(m_validTrap->GetPos());
					GameEngine::GameEngineMain::GetInstance()->AddEntity(trp);
					m_vTraps.push_back(trp);
					m_numOfTraps++;
					GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_validTrap);
					m_validTrap = nullptr;

				}
			}
		}
		
		else
		{
			if (m_validTrap)
			{
				GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_validTrap);
				m_validTrap = nullptr;
			}
			if (m_invalidTrap)
			{
				GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_invalidTrap);
				m_invalidTrap = nullptr;
			}
		}

		for (std::vector<TrapEntity*>::iterator it = m_vTraps.begin(); it != m_vTraps.end();)
		{
			TrapEntity* trp = (*it);
			if (!trp->GetIsActive())
			{
				GameEngine::GameEngineMain::GetInstance()->RemoveEntity(trp);
				it = m_vTraps.erase(it);
				m_numOfTraps--;
			}
			else
			{
				it++;

			}
		}
		
}

