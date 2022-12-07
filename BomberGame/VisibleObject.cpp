#include "VisibleObject.h"
#include <iostream>

VisibleObject::VisibleObject(const sf::Texture& texture) : sprite_(texture)
{

}

void VisibleObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite_);
}

bool VisibleObject::IsContains(float X, float Y) const
{
	return (sprite_.getGlobalBounds().contains(X, Y));
}

void VisibleObject::setPosition(float X, float Y)
{
	X_ = X;
	Y_ = Y;
	sprite_.setPosition(X_, Y_);
}

void VisibleObject::CenterOrigin()
{
	auto result = sprite_.getTextureRect();
	auto origin_center_y = result.height / 2;
	auto origin_center_x = result.width / 2;
	sprite_.setOrigin((float)origin_center_x, (float)origin_center_y);
}
