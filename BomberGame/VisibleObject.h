#pragma once

#include <SFML/Graphics.hpp>

class VisibleObject : public sf::Drawable
{
public:
	VisibleObject(const sf::Texture& texture);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	bool IsContains(float X, float Y) const;
	
	void setPosition(float X, float Y);
	void CenterOrigin();
	void setRelativeOrigin(float rate_X = 0.5, float rate_Y = 0.5);
	void setScale(float X, float Y) { sprite_.setScale(X,Y); }
	void setRotation(float angle); //param angle in degrees
	float getX() { return X_; }
	float getY() { return Y_; }

protected:
	sf::Sprite sprite_;
	float X_ = 0;
	float Y_ = 0;
private:

};

