#pragma once

#include <SFML/Graphics.hpp>

class VisibleObject : public sf::Drawable
{
public:
	VisibleObject(const sf::Texture& texture);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	bool IsContains(sf::Vector2f vec) const;
	
	void CenterOrigin();
	void setRelativeOrigin(float rate_X = 0.5, float rate_Y = 0.5);
	void setScale(float X, float Y) { sprite_.setScale(X,Y); }
	void setColor(sf::Color col) { sprite_.setColor(col); }
	sf::Color getColor() { return sprite_.getColor(); }
	void setRotation(float angle); //param angle in degrees
	sf::FloatRect getCollisionBox() const { return sprite_.getGlobalBounds(); }

	sf::Vector2f getPosition() const { return sprite_.getPosition(); }
	void setPosition(sf::Vector2f position);

protected:
	sf::Sprite sprite_;
	
};

