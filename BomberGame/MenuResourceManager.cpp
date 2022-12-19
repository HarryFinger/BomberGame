#include "MenuResourceManager.h"

#include <cassert>

namespace
{
    struct TexturePath
    {
        const char *filename;
        const MenuResourceManager::TypeTexture type;
    };

    constexpr TexturePath TEXTURE_PATH_ARRAY[] = {
        {"./data/GamePage/background.png", MenuResourceManager::TypeTexture::BACKGROUND},
        {"./data/MenuPage/Button_easy.png", MenuResourceManager::TypeTexture::BUTTON_EASY},
        {"./data/MenuPage/Button_normal.png", MenuResourceManager::TypeTexture::BUTTON_NORMAL},
        {"./data/MenuPage/Button_hard.png", MenuResourceManager::TypeTexture::BUTTON_HARD},
        {"./data/MenuPage/Button_exit.png", MenuResourceManager::TypeTexture::BUTTON_EXIT},
        {"./data/MenuPage/Cursor.png", MenuResourceManager::TypeTexture::CURSOR}};

} // namespace

MenuResourceManager::MenuResourceManager()
{
    sf::Texture texture;
    for (const auto &texture_path : TEXTURE_PATH_ARRAY)
    {
        sf::Texture texture;
        texture.loadFromFile(texture_path.filename);
        texture.setSmooth(1);
        assert(texture_map_.find(texture_path.type) == texture_map_.cend());

        texture_map_.emplace(texture_path.type, texture);
    }
}

const sf::Texture &MenuResourceManager::getTexture(TypeTexture type) const
{
    auto result = texture_map_.find(type);
    if (result != texture_map_.cend())
    {
        return result->second;
    }

    assert(!"Texture not found!");
    return texture_map_.cbegin()->second;
}
