#include "HUDEntity.h"

using namespace Game;

HUDEntity::HUDEntity()
{
	m_textRendererComponent = AddComponent<GameEngine::TextRenderComponent>();
	m_textRendererComponent->SetString("Boxes: 0");
	m_textRendererComponent->SetFont("MilkyNice-Clean.ttf");
	m_textRendererComponent->SetStyle(1);
	m_textRendererComponent->SetCharacterSizePixels(20.0f);
	m_textRendererComponent->SetZLevel(4);

}

HUDEntity::~HUDEntity()
{
}

void HUDEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}

void HUDEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();

}

void HUDEntity::SetText(int txt, int wood)
{
	std::string timeToShow;
	timeToShow.append("Boxes: " + std::to_string(txt) +"\nWoods: "+ std::to_string(wood));
	m_textRendererComponent->SetString(timeToShow);


}
