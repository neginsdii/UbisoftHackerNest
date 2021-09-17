#include "MenuScene.h"
#include "GameEngine/GameEngineMain.h"

using namespace Game;

MenuScene::MenuScene()
	: m_menuBG(nullptr)
{
	m_menuBG = new MenuBGEntity();
	m_menuBG->SetPos(sf::Vector2f(GameEngine::GameEngineMain::GetInstance()->GetWindowWidth() / 2.0f, GameEngine::GameEngineMain::GetInstance()->GetWindowHeight() / 4.0f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_menuBG);

}

MenuScene::~MenuScene()
{
}

void MenuScene::Start()
{
}

void MenuScene::Update()
{

}


void MenuScene::Clean()
{
	GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_menuBG);

}
