#pragma once

#include "Cannonball.h"
#include "VisibleObject.h"

class Cannonball final: public VisibleObject
{
public:
	Cannonball(const sf::Texture& texture);
	void update(float delta_time);
	float getLifeTime() { return time_accumulator; }

	void ChangeForwardVector(sf::Vector2f for_vec);
	float getRadius();
	sf::Vector2f getPositionVector();

private:
	sf::Vector2f forward_vector;
	float speed;
	float time_accumulator = 0.0f;
};