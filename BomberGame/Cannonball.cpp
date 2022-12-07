#include "Cannonball.h"

Cannonball::Cannonball(const sf::Texture& texture): VisibleObject(texture)
{

}

void Cannonball::update(float delta_time)
{
	time_accumulator += delta_time;
}
