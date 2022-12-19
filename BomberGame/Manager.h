#pragma once

#include "Page.h"

#include <SFML/Graphics.hpp>

class Manager final
{
  public:
    Manager(sf::RenderWindow *window);

    void processInput(const sf::Event &event);
    void update(float delta_time);
    void render();

  private:
    std::unique_ptr<Page> current_state;
    sf::RenderWindow *pwindow;
    uint32_t current_difficulty;
};
