#pragma once

#include <SFML/Graphics.hpp>
#include <list>

#include "GameResourceManager.h"
#include "VisibleObject.h"

class Gun final: public sf::Drawable
{
public:
	Gun(const sf::Texture& cannon_texture, const sf::Texture& stand_texture);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void update(float delta_time);

	void updateAimCoordinate(float X, float Y) { aim_X = X; aim_Y = Y; };
	sf::Vector2f getForwardVercor() { return forward_vector; }

private:
	VisibleObject cannon;
	VisibleObject stand;

	sf::Vector2f forward_vector;

	float aim_X = 0.0f;
	float aim_Y = 0.0f;
};

