#include "Tools.h"

namespace
{
    constexpr uint32_t WINDOW_WIDTH_SIZE = 1024u;
    constexpr uint32_t WINDOW_HEIGHT_SIZE = 768u;
    constexpr float FPS = 1.0f / 30.0f;
    constexpr float PI = 3.1415926f;
    constexpr float RAD_TO_DEGREES = 180.0f/ PI;
    constexpr float CANNON_ROTATION_LIMIT = 45.0f;

} // namespace

namespace tools
{
    uint32_t getWindowWidth()
    {
        return WINDOW_WIDTH_SIZE;
    }

    uint32_t getWindowHeight()
    {
        return WINDOW_HEIGHT_SIZE;
    }

    float getFPS()
    {
        return FPS;
    }

    float getRadToDegrees()
    {
        return RAD_TO_DEGREES;
    }

    float getRightCannonRotLimit()
    {
        return CANNON_ROTATION_LIMIT;
    }

    float getLeftCannonRotLimit()
    {
        return -CANNON_ROTATION_LIMIT;
    }


} // namespace tools