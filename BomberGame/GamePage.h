#pragma once

#include "Cannonball.h"
#include "Cursor.h"
#include "GameResourceManager.h"
#include "Gun.h"
#include "Page.h"
#include "Target.h"
#include "Timer.h"
#include "VisibleObject.h"

#include <SFML/Graphics.hpp>

class GamePage final : public Page
{

public:
    GamePage(uint32_t target_number);

    void processInput(const sf::Event &event);
    void update(float delta_time);
    void render(sf::RenderWindow &window) override;

private:
    void CreateCannonball(sf::Vector2f for_vec, float speed);
    void CreateTarget();

private:
    GameResourceManager res_manager;

    Gun gun;
    Timer timer;

    Cursor cursor;
    VisibleObject background;
    VisibleObject win;
    VisibleObject lose;

    std::list<Cannonball> cannonball_list;
    std::list<Target> target_list;

    enum class State
    {
        WIN,
        LOSE,
        IDLE,
    };

    State state = State::IDLE;
};
