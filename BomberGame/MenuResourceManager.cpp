#include "MenuResourceManager.h"
#include <iostream>
#include <cassert>

MenuResourceManager::MenuResourceManager()
{

	sf::Texture texture;
	texture.loadFromFile("./data/MenuPage/background.png");
	texture_map_.emplace(TypeTexture::BACKGROUND, texture );

	texture.loadFromFile("./data/MenuPage/Button_01.png");
	texture_map_.emplace(TypeTexture::BUTTON_1, texture);
	texture.loadFromFile("./data/MenuPage/Button_02.png");
	texture_map_.emplace(TypeTexture::BUTTON_2, texture);
	texture.loadFromFile("./data/MenuPage/Button_03.png");
	texture_map_.emplace(TypeTexture::BUTTON_3, texture);

	texture.loadFromFile("./data/MenuPage/cursor.png");
	texture_map_.emplace(TypeTexture::CURSOR, texture);

}

const sf::Texture& MenuResourceManager::getTexture(TypeTexture type) const
{
	auto result =  texture_map_.find(type);
	assert(result != texture_map_.end());
	return result->second;
}
