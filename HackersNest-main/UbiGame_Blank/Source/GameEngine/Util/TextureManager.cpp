#include "TextureManager.h"

using namespace GameEngine;

TextureManager* TextureManager::sm_instance = nullptr;

TextureManager::TextureManager()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		m_textures[a] = nullptr;
	}
}


TextureManager::~TextureManager()
{
	UnLoadTextures();
}


void TextureManager::LoadTextures()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		sf::Texture* texture = new sf::Texture();
		std::string filePath;
		filePath.append("Resources/img/");
		filePath.append(GetPath((eTexture::type)a));
		texture->loadFromFile(filePath);

		m_textures[a] = texture;
	}
}


void TextureManager::UnLoadTextures()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		delete m_textures[a];
		m_textures[a] = nullptr;
	}
}

namespace TextureHelper
{
    sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture)
    {
        switch (texture)
        {
		case  GameEngine::eTexture::Player:		return sf::Vector2f(16.f, 27.f);
        case  GameEngine::eTexture::Tileset: return sf::Vector2f(32.f, 32.f);
		case  GameEngine::eTexture::BGMenu:	      return sf::Vector2f(816.f, 290.f);
		case  GameEngine::eTexture::Particles:	 return sf::Vector2f(31.f, 32.f);
		case  GameEngine::eTexture::BGGame:	     return sf::Vector2f(1609.f, 290.f);
		case  GameEngine::eTexture::BGGame2:	     return sf::Vector2f(1609.f, 290.f);
		case  GameEngine::eTexture::Sewage:		  return sf::Vector2f(1609.f, 290.f);
		case  GameEngine::eTexture::Pipe:		return sf::Vector2f(288.f, 72.f);
		case  GameEngine::eTexture::Rat:   return sf::Vector2f(65.f, 27.f);
		case  GameEngine::eTexture::Bridge:   return sf::Vector2f(96.f, 27.f);
		case  GameEngine::eTexture::ValidBridge:   return sf::Vector2f(96.f, 27.f);
		case  GameEngine::eTexture::InvalidBridge:   return sf::Vector2f(96.f, 27.f);

		default:							 return sf::Vector2f(-1.f, -1.f);
        }
    }
}
