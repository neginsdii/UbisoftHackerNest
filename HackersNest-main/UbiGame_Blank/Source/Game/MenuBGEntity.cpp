#include "MenuBGEntity.h"
using namespace Game;

MenuBGEntity::MenuBGEntity()
{
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::BGMenu);
	m_renderComponent->SetZLevel(0);

	SetEntityTag("MenuBG");

}

MenuBGEntity::~MenuBGEntity()
{
}

void MenuBGEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}

void MenuBGEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}
