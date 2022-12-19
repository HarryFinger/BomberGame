#pragma once

#include <SFML/Graphics.hpp>

namespace tools
{
    float getWindowWidth();
    float getWindowHeight();
    float getFPS();
    float RadianToDegrees();
    float DegreesToRadian();
    float getCannonRotationLimit();

    // collision part
    float DotProduct(const sf::Vector2f &a, const sf::Vector2f &b);
    float DistanceBetweenObjects(const sf::Vector2f &a, const sf::Vector2f &b);
    sf::Vector2f NormalizeVector(const sf::Vector2f &vec);
    sf::Vector2f CalcNormalizeReflectionVector(const sf::Vector2f &inc_vec, const sf::Vector2f &normal_vec);

    template <typename T> constexpr T Clamp(const T &v, const T &from, const T &to)
    {
        return (v < from) ? from : ((v > to) ? to : v);
    }
} // namespace tools
