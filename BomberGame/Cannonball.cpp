#include "Cannonball.h"

Cannonball::Cannonball(const sf::Texture& texture, sf::Vector2f position, sf::Vector2f for_vec, float speed)
	: VisibleObject(texture), forward_vector_(for_vec), speed_(speed)
{
	CenterOrigin();
	sprite_.setPosition(position);
}

void Cannonball::update(float delta_time)
{
	life_time -= delta_time;
	sf::Vector2f new_vec = forward_vector_ * delta_time * speed_;
	sprite_.setPosition(sprite_.getPosition() + new_vec);
}

bool Cannonball::IsDead()
{
	return (life_time < 0.f);
}

void Cannonball::ChangeForwardVector(sf::Vector2f for_vec)
{
	forward_vector_ = for_vec;
}

float Cannonball::getRadius()
{
	return sprite_.getTextureRect().height / 2.f;
}
