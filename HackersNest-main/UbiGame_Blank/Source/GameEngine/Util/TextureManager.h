#pragma once
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameEngine
{
	//TODO - if needed, move out of Engine part to some sort of loader on the game side of things
	namespace eTexture
	{
		enum type
		{
			None = -1,
			Player = 0,
			Tileset,
			BGMenu,
			BGGame,
			BGGame2,
			Particles,
			Pipe,
			Sewage,
			Rat,
			Count,
		};
	}	

	inline const char* GetPath(eTexture::type texture)
	{
		switch (texture)
		{
		case eTexture::Player:    return "player.png";
		case eTexture::Tileset:   return "tileset.png";
		case eTexture::BGMenu:		  return "MenuBG.png";
		case eTexture::Particles: return "particles.png";
		case eTexture::BGGame: return "GameBG.png";
		case eTexture::Pipe:	return "Pipe.png";
		case eTexture::BGGame2:	return "GameBG2.png";
		case eTexture::Sewage:	return "Sewage.png";
		case eTexture::Rat:	return "Rat.png";

		default:       return "UnknownTexType";
		}
	}

	class TextureManager
	{
	public:
		static TextureManager* GetInstance() { if (!sm_instance) sm_instance = new TextureManager(); return sm_instance; }
		~TextureManager();

		void LoadTextures();
		void UnLoadTextures();

		sf::Texture* GetTexture(eTexture::type texture) const { return m_textures[(int)texture]; }

	private:
		TextureManager();
		static TextureManager* sm_instance;

		sf::Texture* m_textures[eTexture::Count];
	};
}

namespace TextureHelper
{
	sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture);
}

