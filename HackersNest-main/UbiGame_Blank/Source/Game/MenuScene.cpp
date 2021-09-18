#include "MenuScene.h"
#include "GameEngine/GameEngineMain.h"

using namespace Game;

MenuScene::MenuScene()
	: m_menuBG(nullptr)
{
	m_menuBG = new MenuBGEntity();
	m_menuBG->SetPos(sf::Vector2f(GameEngine::GameEngineMain::GetInstance()->GetWindowWidth() / 2.0f, GameEngine::GameEngineMain::GetInstance()->GetWindowHeight() / 4.0f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_menuBG);

	m_Player = new PlayerEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_Player);
	m_Player->SetPos(sf::Vector2f(3 * GameEngine::GameEngineMain::GetInstance()->GetWindowWidth() / 10.0f, GameEngine::GameEngineMain::GetInstance()->GetWindowHeight() / 3.0f + 30.f));
	m_Player->SetSize(TextureHelper::GetTextureTileSize(GameEngine::eTexture::Player) * 3.0f);
	
	m_platform = new PlatformEntity();
	m_platform->SetPos(sf::Vector2f(GameEngine::GameEngineMain::GetInstance()->GetWindowWidth() / 2.0f, GameEngine::GameEngineMain::GetInstance()->GetWindowHeight() / 2.0f - 50.0f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_platform);

}

MenuScene::~MenuScene()
{
}

void MenuScene::Start()
{
}

void MenuScene::Update()
{
	if (m_Player->GetPos().x >= m_menuBG->GetPos().x + 240.0f)
		m_Player->SetPos(sf::Vector2f(3 * GameEngine::GameEngineMain::GetInstance()->GetWindowWidth() / 10.0f, GameEngine::GameEngineMain::GetInstance()->GetWindowHeight() / 4.0f));

}


void MenuScene::Clean()
{
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_menuBG);
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_Player);
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_platform);

}
