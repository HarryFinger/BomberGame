#pragma once

#include "Cannonball.h"
#include "VisibleObject.h"

class Cannonball final: public VisibleObject
{
public:
	Cannonball(const sf::Texture& texture, sf::Vector2f position, sf::Vector2f for_vec, float speed);
	void update(float delta_time);
	bool IsDead();

	void ChangeForwardVector(sf::Vector2f for_vec);
	float getRadius();

private:
	sf::Vector2f forward_vector_;
	float speed_;
	float life_time = 3.5f;
};