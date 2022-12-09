#pragma once

#include <SFML/Graphics.hpp>

class VisibleObject : public sf::Drawable
{
public:
	VisibleObject(const sf::Texture& texture);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	bool IsContains(sf::Vector2f vec) const;
	
	void setPosition(sf::Vector2f pos);
	void CenterOrigin();
	void setRelativeOrigin(float rate_X = 0.5, float rate_Y = 0.5);
	void setScale(float X, float Y) { sprite_.setScale(X,Y); }
	void setRotation(float angle); //param angle in degrees
	sf::Vector2f getPosition() { return position; }
		
protected:
	sf::Sprite sprite_;
	sf::Vector2f position;
};

