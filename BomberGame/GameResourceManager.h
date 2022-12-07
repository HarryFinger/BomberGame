#pragma once
#include <SFML/Graphics.hpp>

#include <unordered_map>


class GameResourceManager final
{
public:
	enum class TypeTexture
	{
		BACKGROUND,
		AIM,
		CANNON,
		STAND,
		CANNONBALL,
		TARGET,
		CLOCK
	};
	enum class TypeFont
	{
		FRUIT_DAYS
	};

private:
	std::unordered_map<TypeTexture, sf::Texture> texture_map_;
	std::unordered_map<TypeFont, sf::Font> font_map_;

public:
	GameResourceManager();
	const sf::Texture& getTexture(TypeTexture type) const;
	const sf::Font& getFont(TypeFont type) const;

};