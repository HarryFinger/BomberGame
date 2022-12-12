#pragma once

#include "Cannonball.h"
#include "VisibleObject.h"

class Cannonball final: public VisibleObject
{
public:
	Cannonball(const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& for_vec, float speed);
	void update(float delta_time);
	bool IsDead();

	float getRadius();

private:
	const sf::Vector2f forward_vector_;
	const float speed_;
	float life_time = 3.5f;
};