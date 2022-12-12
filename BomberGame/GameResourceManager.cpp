#include "GameResourceManager.h"

#include <cassert>

namespace
{
	struct TexturePath
	{
		const char* filename;
		const GameResourceManager::TypeTexture type;
	};

	constexpr TexturePath TexturePaths[] =
	{
		{ "./data/GamePage/background.png", GameResourceManager::TypeTexture::BACKGROUND},
		{ "./data/GamePage/Aim.png", GameResourceManager::TypeTexture::AIM},
		{ "./data/GamePage/Cannon.png", GameResourceManager::TypeTexture::CANNON},
		{ "./data/GamePage/Stand.png", GameResourceManager::TypeTexture::STAND},
		{ "./data/GamePage/Cannonball.png", GameResourceManager::TypeTexture::CANNONBALL},
		{ "./data/GamePage/Target.png", GameResourceManager::TypeTexture::TARGET},
		{ "./data/GamePage/Clock.png", GameResourceManager::TypeTexture::CLOCK},
		{ "./data/GamePage/Shield.png", GameResourceManager::TypeTexture::SHIELD},
		{ "./data/GamePage/Win.png", GameResourceManager::TypeTexture::WIN},
		{ "./data/GamePage/Lose.png", GameResourceManager::TypeTexture::LOSE},
	};

} // namespace

GameResourceManager::GameResourceManager()
{
	// texture emplacing
	for (const auto& texture_path : TexturePaths)
	{
		sf::Texture texture;
		texture.loadFromFile(texture_path.filename);
		texture.setSmooth(1);
		assert(texture_map_.find(texture_path.type) == texture_map_.cend());

		texture_map_.emplace(texture_path.type, texture);
	}

	// font emplacing
	sf::Font font;
	font.loadFromFile("./data/GamePage/font/fruit_days.ttf");
	font_map_.emplace(TypeFont::FRUIT_DAYS, font);
}

const sf::Texture& GameResourceManager::getTexture(TypeTexture type) const
{
	auto result = texture_map_.find(type);
	if (result != texture_map_.cend())
	{
		return result->second;
	}

	assert(!"Texture not found!");
	return texture_map_.cbegin()->second;
}

const sf::Font& GameResourceManager::getFont(TypeFont type) const
{
	auto result = font_map_.find(type);
	if (result != font_map_.cend())
	{
		return result->second;
	}

	assert(!"Texture not found!");
	return font_map_.cbegin()->second;
}
