#pragma once

#include "Cannonball.h"
#include "VisibleObject.h"

class Cannonball final: public VisibleObject
{
public:
	Cannonball(const sf::Texture& texture, sf::Vector2f for_vec, float speed);
	void update(float delta_time);
	float getLifeTime() { return time_accumulator_; }

	void ChangeForwardVector(sf::Vector2f for_vec);
	float getRadius();
	sf::Vector2f getPositionVector();

private:
	sf::Vector2f forward_vector_;
	float speed_;
	float time_accumulator_ = 0.0f;
};