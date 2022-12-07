#pragma once
#include <SFML/Graphics.hpp>

#include<string>
#include<unordered_map>


class MenuResourceManager final
{
public:
	enum class TypeTexture
	{
		BACKGROUND,
		BUTTON_1,
		BUTTON_2,
		BUTTON_3,
		CURSOR
	};

public:
	MenuResourceManager();
	const sf::Texture& getTexture(TypeTexture type) const;
private:
	std::unordered_map<TypeTexture, sf::Texture> texture_map_;
};