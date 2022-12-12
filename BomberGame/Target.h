#pragma once

#include "VisibleObject.h"

class Target : public VisibleObject
{
public:
	enum class Type
	{
		GREEN,
		YELLOW,
		RED
	};

public:
	Target(const sf::Texture& texture, Type type, sf::Vector2f for_vec, sf::Vector2f position);
	void update(float delta_time);
	void ChangeForwardVector(sf::Vector2f for_vec) { forward_vector = for_vec; };
	float getRadius() { return radius; }
	bool IsDead();
	void DealingDamage();

private:
	sf::Vector2f forward_vector;
	float radius;
	float speed;
	float hit_points = 100.f;
	Type type_ = Type::GREEN;
};

