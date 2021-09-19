#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include "GameEngine/EntitySystem/Components/RenderComponent.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "GameEngine/Util/TextureManager.h"

namespace GameEngine
{	
	class SpriteRenderComponent : public RenderComponent
	{
	public:
		SpriteRenderComponent();
		virtual ~SpriteRenderComponent();

		virtual void Update() override;
		void UpdateTileRect();
		virtual void Render(sf::RenderTarget* target) override;
		virtual void OnAddToWorld() override;

		void SetTexture(eTexture::type texture);
		eTexture::type GetTexture() const { return m_texture; }

		void SetTileIndex(sf::Vector2i vect) { m_tileIndex = vect; }
		void SetTileIndex(int xIdx, int yIdx) { m_tileIndex = sf::Vector2i(xIdx, yIdx); }

		void UpdateSpriteParams();
		void SetScale(sf::Vector2f scl);
		sf::Vector2f GetScale() const { return m_sprite.getScale(); }

	private:
		eTexture::type  m_texture;
		sf::Vector2i	m_tileIndex;

		sf::Sprite m_sprite;
		AnimationComponent* m_animComponent;
	};
}


