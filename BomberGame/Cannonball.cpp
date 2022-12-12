#include "Cannonball.h"

Cannonball::Cannonball(const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& for_vec, float speed)
	: VisibleObject(texture)
	, forward_vector_(for_vec)
	, speed_(speed)
{
	CenterOrigin();
	sprite_.setPosition(position);
}

void Cannonball::update(float delta_time)
{
	life_time -= delta_time;
	const auto new_vec = forward_vector_ * delta_time * speed_;
	sprite_.setPosition(sprite_.getPosition() + new_vec);
}

bool Cannonball::IsDead()
{
	return life_time < 0.0f;
}

float Cannonball::getRadius()
{
	return 0.5f * sprite_.getTextureRect().height;
}
