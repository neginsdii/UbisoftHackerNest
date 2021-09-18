#include "PipeEntity.h"

using namespace Game;

PipeEntity::PipeEntity()
{
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::Pipe);
	m_renderComponent->SetZLevel(1);

	AddComponent<GameEngine::CollidableComponent>();
	GetComponent<GameEngine::CollidableComponent>()->SetBoundingBox(sf::Vector2f(288.0f, 60.0f));

	SetEntityTag("Platform");

}

PipeEntity::~PipeEntity()
{
}

void PipeEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();
}

void PipeEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();

}
