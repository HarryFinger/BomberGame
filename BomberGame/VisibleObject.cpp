#include "VisibleObject.h"
#include <iostream>

VisibleObject::VisibleObject(const sf::Texture &texture) : sprite_(texture)
{
}

void VisibleObject::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite_);
}

bool VisibleObject::IsContains(const sf::Vector2f &vec) const
{
    return sprite_.getGlobalBounds().contains(vec);
}

void VisibleObject::setPosition(const sf::Vector2f &position)
{
    sprite_.setPosition(position);
}

void VisibleObject::CenterOrigin()
{
    setRelativeOrigin({0.5f, 0.5f});
}

void VisibleObject::setRelativeOrigin(const sf::Vector2f &rate)
{
    const auto &rect = sprite_.getTextureRect();
    const auto coordinate_X = rect.width * rate.x;
    const auto coordinate_Y = rect.height * rate.y;
    sprite_.setOrigin(coordinate_X, coordinate_Y);
}

void VisibleObject::setRotation(float angle)
{
    sprite_.setRotation(angle);
}
