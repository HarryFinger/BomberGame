#include "Button.h"

namespace
{
    constexpr float SCALE_FACTOR = 1.12f;

} // namespace

Button::Button(const sf::Texture &texture, Button::Type type)
    : VisibleObject(texture), type_(type), original_scale(sprite_.getScale())
{
    this->CenterOrigin();
}

void Button::update(float delta_time)
{
    VisibleObject::update(delta_time);

    if (on_hover)
    {
        setScale(SCALE_FACTOR);
    }
    else
    {
        setScale(1.0f);
    }
    on_hover = false;
}

void Button::setScale(float scale)
{
    sprite_.setScale(original_scale * scale);
}
