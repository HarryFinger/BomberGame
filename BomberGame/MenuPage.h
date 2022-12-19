#pragma once

#include "Button.h"
#include "Cursor.h"
#include "MenuResourceManager.h"
#include "Page.h"
#include "VisibleObject.h"

#include <list>

class MenuPage final : public Page
{
  public:
    MenuPage();
    void processInput(const sf::Event &event) override;
    void update(float delta_time) override;
    void render(sf::RenderWindow &window) override;

    uint32_t getGameDifficulty() const
    {
        return game_difficulty;
    }

  private:
    MenuResourceManager res_manager;

    std::list<VisibleObject> object_list;
    std::list<Button> button_list;
    Cursor cursor;
    uint32_t game_difficulty;
    bool is_left_button_clicked = false;

  private:
    Button *getButtonOnHover();
};
