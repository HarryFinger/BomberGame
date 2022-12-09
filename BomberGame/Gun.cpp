#include "Gun.h"
#include "Tools.h"
#include <iostream>

Gun::Gun(const sf::Texture& cannon_texture, const sf::Texture& stand_texture):
	  cannon(cannon_texture)
	, stand(stand_texture)
{
	stand.CenterOrigin();
	stand.setPosition(tools::getWindowWidth() / 2.0f, 19.0f * tools::getWindowHeight() / 20.0f);

	cannon.setRelativeOrigin(0.5f, 0.69f);
	cannon.setPosition(tools::getWindowWidth() / 2.0f, 18.1f * tools::getWindowHeight() / 20.0f);
}

// UPDATE STATE
void Gun::update(float delta_time)
{
	// todo
	forward_vector = tools::NormalizeVector(sf::Vector2f(aim_X - cannon.getX(), aim_Y - cannon.getY()));

	// sf::Vector2f(0.f, -1.f) is unit vector pointing up
	float alpha = std::acos(tools::DotProduct(sf::Vector2f(0.0f, -1.0f), forward_vector)) * tools::getRadToDegrees();

	if (aim_X < tools::getWindowWidth() / 2.0f)
	{
		alpha *= -1.0f;
	}

	// converting to new coordinate system

	/*float l_X = aim_X - cannon.getX();
	float l_Y = cannon.getY() - aim_Y;
	auto angle = std::atan2(l_X, l_Y) * tools::getRadToDegrees();*/



	/*if (angle >= tools::getRightCannonRotLimit())
	{
		angle = tools::getRightCannonRotLimit();
	}

	if (angle <= tools::getLeftCannonRotLimit())
	{
		angle = tools::getLeftCannonRotLimit();
	}*/
	alpha = tools::Clamp(alpha, -tools::getCanRotLimit(), tools::getCanRotLimit());

	cannon.setRotation(alpha);

	// create cannonball
	
}

// RENDER STATE
void Gun::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(stand);
	target.draw(cannon);
}