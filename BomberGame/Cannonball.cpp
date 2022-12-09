#include "Cannonball.h"

Cannonball::Cannonball(const sf::Texture& texture, sf::Vector2f for_vec, float speed)
	: VisibleObject(texture), forward_vector_(for_vec), speed_(speed)
{

}

void Cannonball::update(float delta_time)
{
	time_accumulator_ += delta_time;

	//float newX = forward_vector_.x * delta_time * speed_;
	//sprite_.setPosition()
}

void Cannonball::ChangeForwardVector(sf::Vector2f for_vec)
{
	forward_vector_ = for_vec; 
}

float Cannonball::getRadius()
{
	return sprite_.getTextureRect().height / 2.f;
}

sf::Vector2f Cannonball::getPositionVector()
{
	return sf::Vector2f(position);
}
