#pragma once

#include <SFML/Graphics.hpp>

class VisibleObject : public sf::Drawable
{
public:
    VisibleObject(const sf::Texture &texture);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    virtual void update(float /*delta_time*/)
    {
    }

    bool IsContains(const sf::Vector2f &vec) const;

    void CenterOrigin();

    void setRelativeOrigin(const sf::Vector2f &rate);

    void setScale(float X, float Y)
    {
        sprite_.setScale(X, Y);
    }

    void setColor(const sf::Color &col)
    {
        sprite_.setColor(col);
    }

    const sf::Color &getColor() const
    {
        return sprite_.getColor();
    }

    void setRotation(float angle); // param angle in degrees

    sf::FloatRect getCollisionBox() const
    {
        return sprite_.getGlobalBounds();
    }

    const sf::Vector2f &getPosition() const
    {
        return sprite_.getPosition();
    }

    void setPosition(const sf::Vector2f &position);

protected:
    sf::Sprite sprite_;
};
