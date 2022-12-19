#include "Tools.h"

namespace
{
constexpr auto WINDOW_WIDTH_SIZE = 1024.0f;
    constexpr auto WINDOW_HEIGHT_SIZE = 768.0f;
    constexpr auto FPS = 1.0f / 30.0f;
    constexpr auto PI = 3.1415926f;
    constexpr auto RAD_TO_DEGREES = 180.0f / PI;
    constexpr auto DEGREES_TO_RAD = PI / 180.0f;

    constexpr auto CANNON_ROTATION_LIMIT = 70.0f;

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
    float DotProduct(const sf::Vector2f &a, const sf::Vector2f &b)
    {
        return a.x * b.x + a.y * b.y;
    }

    float DistanceBetweenObjects(const sf::Vector2f &a, const sf::Vector2f &b)
    {
        return std::sqrt(std::pow(a.x - b.x, 2.0f) + std::pow(a.y - b.y, 2.0f));
    }

    sf::Vector2f NormalizeVector(const sf::Vector2f &vec)
    {
        const auto ratio = 1.0f / std::sqrt(vec.x * vec.x + vec.y * vec.y);
        return vec * ratio;
    }

    sf::Vector2f CalcNormalizeReflectionVector(const sf::Vector2f &inc_vec, const sf::Vector2f &normal_vec)
    {
        const auto dot_prod = DotProduct(inc_vec, normal_vec);
        const auto p_vec = dot_prod * normal_vec;
        return NormalizeVector(inc_vec - (2.0f * p_vec));
    }

} // namespace tools