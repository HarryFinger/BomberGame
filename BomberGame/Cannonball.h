#pragma once

#include "VisibleObject.h"

class Cannonball final: public VisibleObject
{
public:
	Cannonball(const sf::Texture& texture);
	sf::Vector2f forward_vector;
	void update(float delta_time);
	float getLifeTime() { return time_accumulator; }
private:
	float time_accumulator = 0.0f;
};