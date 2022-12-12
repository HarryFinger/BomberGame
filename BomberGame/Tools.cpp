#include "Tools.h"

namespace
{
    constexpr float WINDOW_WIDTH_SIZE = 1024.f;
    constexpr float WINDOW_HEIGHT_SIZE = 768.f;
    constexpr float FPS = 1.0f / 30.0f;
    constexpr float PI = 3.1415926f;
    constexpr float RAD_TO_DEGREES = 180.0f / PI;
    constexpr float DEGREES_TO_RAD = PI / 180.0f;

    constexpr float CANNON_ROTATION_LIMIT = 60.0f;

} // namespace

namespace tools
{
    float getWindowWidth()
    {
        return WINDOW_WIDTH_SIZE;
    }

    float getWindowHeight()
    {
        return WINDOW_HEIGHT_SIZE;
    }

    float getFPS()
    {
        return FPS;
    }
    // convert to degrtees
    float RadianToDegrees()
    {
        return RAD_TO_DEGREES;
    }

    float DegreesToRadian()
    {
        return DEGREES_TO_RAD;
    }

    float getCannonRotationLimit()
    {
        return CANNON_ROTATION_LIMIT;
    }

    // collision part
    float DotProduct(sf::Vector2f a, sf::Vector2f b)
    {
        return  a.x * b.x + a.y * b.y;
    }

    float DistanceBetweenTwoObjects(sf::Vector2f a, sf::Vector2f b)
    {
        return (float)std::sqrt(std::pow((a.x - b.x), 2) + std::pow((a.y - b.y), 2));
    }

    sf::Vector2f NormalizeVector(sf::Vector2f vec)
    {
        float length = (float)(std::sqrt(vec.x * vec.x + vec.y * vec.y));
        float X = vec.x / length;
        float Y = vec.y / length;
        return sf::Vector2f(X, Y);
    }

    sf::Vector2f CalcNormalizeReflectionVector(sf::Vector2f inc_vec, sf::Vector2f normal_vec)
    {
        float dot_prod = DotProduct(inc_vec, normal_vec);
        sf::Vector2f p_vec = dot_prod * normal_vec;
        return NormalizeVector(inc_vec - (2.f * p_vec));
    }

} // namespace tools