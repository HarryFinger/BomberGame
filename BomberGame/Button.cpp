#include "Button.h"

namespace
{
	constexpr float SCALE_FACTOR = 1.12f;

} // namespace

Button::Button(const sf::Texture& texture, Button::Type type) : VisibleObject(texture), type_(type)
{
	this->CenterOrigin();
	original_scale = sprite_.getScale();
}

void Button::update(float delta_time)
{
	if (on_hover)
	{
		ScaleUp();
	}
	else
	{
		ResetScale();
	}
	on_hover = false;
}

void Button::ScaleUp()
{
	sprite_.setScale(original_scale.x * SCALE_FACTOR, original_scale.y * SCALE_FACTOR);
}

void Button::ResetScale()
{
	sprite_.setScale(original_scale);
}
