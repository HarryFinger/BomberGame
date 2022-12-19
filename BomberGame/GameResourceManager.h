#pragma once
#include <SFML/Graphics.hpp>

#include <unordered_map>

class GameResourceManager final
{
public:
    GameResourceManager();

public:
    enum class TypeTexture
    {
        BACKGROUND,
        AIM,
        CANNON,
        STAND,
        CANNONBALL,
        TARGET,
        CLOCK,
        SHIELD,
        WIN,
        LOSE,
    };
    enum class TypeFont
    {
        FRUIT_DAYS,
    };

    const sf::Texture &getTexture(TypeTexture type) const;
    const sf::Font &getFont(TypeFont type) const;

private:
    std::unordered_map<TypeTexture, sf::Texture> texture_map_;
    std::unordered_map<TypeFont, sf::Font> font_map_;
};