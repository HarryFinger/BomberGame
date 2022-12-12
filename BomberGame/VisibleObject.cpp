#include "VisibleObject.h"
#include <iostream>

VisibleObject::VisibleObject(const sf::Texture& texture) : sprite_(texture)
{
}

void VisibleObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite_);
}

bool VisibleObject::IsContains(sf::Vector2f vec) const
{
	return (sprite_.getGlobalBounds().contains(vec));
}

void VisibleObject::setPosition(sf::Vector2f position)
{
	sprite_.setPosition(position);
}

void VisibleObject::CenterOrigin()
{
	auto result = sprite_.getTextureRect();
	auto origin_center_y = result.height / 2.0f;
	auto origin_center_x = result.width / 2.0f;
	sprite_.setOrigin(origin_center_x, origin_center_y);
}

void VisibleObject::setRelativeOrigin(float rate_X, float rate_Y)
{
	float coordinate_X = sprite_.getTextureRect().width * rate_X;
	float coordinate_Y = sprite_.getTextureRect().height * rate_Y;
	sprite_.setOrigin(coordinate_X, coordinate_Y);
}

void VisibleObject::setRotation(float angle)
{
	sprite_.setRotation(angle);
}

