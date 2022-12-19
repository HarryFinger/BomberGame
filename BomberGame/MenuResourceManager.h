#pragma once
#include <SFML/Graphics.hpp>

#include <unordered_map>

class MenuResourceManager final
{
public:
    enum class TypeTexture
    {
        BACKGROUND,
        BUTTON_EASY,
        BUTTON_NORMAL,
        BUTTON_HARD,
        BUTTON_EXIT,
        CURSOR,
    };

public:
    MenuResourceManager();
    const sf::Texture &getTexture(TypeTexture type) const;

private:
    std::unordered_map<TypeTexture, sf::Texture> texture_map_;
};