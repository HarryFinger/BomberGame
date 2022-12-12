#include "Cursor.h"



Cursor::Cursor(const sf::Texture& texture) : VisibleObject(texture)
{
	original_scale = sprite_.getScale();
}

void Cursor::update(float delta_time)
{
	if (is_flicks)
	{
		Flicker(delta_time);
	}
}

void Cursor::StartFlicker()
{
	is_flicks = true;
}

void Cursor::Flicker(float delta_time)
{
	time_accumulator += delta_time; //potential inf
	float scale = std::sin(time_accumulator * frequency)/10.f + 1.f;
	sprite_.setScale(scale, scale);
}

void Cursor::StopFlicker()
{
	sprite_.setScale(original_scale);
	is_flicks = false;
}

