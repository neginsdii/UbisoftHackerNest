#include "GameBGEntity.h"
using namespace Game;

GameBGEntity::GameBGEntity()
{
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	//m_renderComponent->SetTexture(GameEngine::eTexture::BGGame);
	m_renderComponent->SetZLevel(0);
	SetEntityTag("GameBG");

}

GameBGEntity::~GameBGEntity()
{
}

void GameBGEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}

void GameBGEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}
