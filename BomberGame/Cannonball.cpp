#include "Cannonball.h"

Cannonball::Cannonball(const sf::Texture& texture): VisibleObject(texture)
{

}

void Cannonball::update(float delta_time)
{
	time_accumulator += delta_time;
}

void Cannonball::ChangeForwardVector(sf::Vector2f for_vec)
{
	forward_vector = for_vec; 
}

float Cannonball::getRadius()
{
	return sprite_.getTextureRect().height / 2.f;
}

sf::Vector2f Cannonball::getPositionVector()
{
	return sf::Vector2f(X_, Y_);
}
