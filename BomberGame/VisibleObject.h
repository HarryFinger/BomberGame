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
	float getX() { return X_; }
	float getY() { return Y_; }

protected:
	sf::Sprite sprite_;
	float X_ = 0;
	float Y_ = 0;
private:

};

