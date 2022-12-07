#include "Tools.h"

namespace
{
    constexpr uint32_t WINDOW_WIDTH_SIZE = 1024u;
    constexpr uint32_t WINDOW_HEIGHT_SIZE = 768u;
    constexpr float FPS = 1.0f / 5.0f;


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

} // namespace tools