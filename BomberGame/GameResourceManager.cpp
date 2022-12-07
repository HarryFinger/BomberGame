#include "GameResourceManager.h"

#include <cassert>

GameResourceManager::GameResourceManager()
{
	// texture emplacing 
	sf::Texture texture;
	texture.loadFromFile("./data/GamePage/background.png");
	texture_map_.emplace(TypeTexture::BACKGROUND, texture); 

	texture.loadFromFile("./data/GamePage/Aim.png");
	texture.setSmooth(1);
	texture_map_.emplace(TypeTexture::AIM, texture);

	texture.loadFromFile("./data/GamePage/Cannon.png");
	texture.setSmooth(1);
	texture_map_.emplace(TypeTexture::CANNON, texture);

	texture.loadFromFile("./data/GamePage/Stand.png");
	texture.setSmooth(1);
	texture_map_.emplace(TypeTexture::STAND, texture);

	texture.loadFromFile("./data/GamePage/Cannonball.png");
	texture.setSmooth(1);
	texture_map_.emplace(TypeTexture::CANNONBALL, texture);

	texture.loadFromFile("./data/GamePage/Target.png");
	texture.setSmooth(1);
	texture_map_.emplace(TypeTexture::TARGET, texture);

	texture.loadFromFile("./data/GamePage/Clock.png");
	texture.setSmooth(1);
	texture_map_.emplace(TypeTexture::CLOCK, texture);

	// font emplacing
	sf::Font font;
	font.loadFromFile("./data/GamePage/font/fruit_days.ttf");
	font_map_.emplace(TypeFont::FRUIT_DAYS, font);
}

const sf::Texture& GameResourceManager::getTexture(TypeTexture type) const
{
	auto result = texture_map_.find(type);
	assert(result != texture_map_.end());
	return result->second;
}

const sf::Font& GameResourceManager::getFont(TypeFont type) const
{
	auto result = font_map_.find(type);
	assert(result != font_map_.end());
	return result->second;
}
