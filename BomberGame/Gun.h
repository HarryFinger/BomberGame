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

	void UpdateAimPosition(sf::Vector2f pos) { aim_position = pos; };
	sf::Vector2f getForwardVercor() { return forward_vector; }

private:
	VisibleObject cannon;
	VisibleObject stand;

	sf::Vector2f forward_vector;

	sf::Vector2f aim_position;
};

