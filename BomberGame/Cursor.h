#pragma once

#include "VisibleObject.h"

class Cursor : public VisibleObject
{
public:
    Cursor(const sf::Texture &texture);
    void update(float delta_time);
    void StartFlicker();
    void StopFlicker();

private:
    void Flicker(float delta_time);

private:
    sf::Vector2f original_scale;
    float time_accumulator = 0.0f;
    float frequency = 5.0f;
    bool is_flicks = false;
};
