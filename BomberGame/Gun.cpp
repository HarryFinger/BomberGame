#include "Gun.h"
#include "Tools.h"


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
	// converting to new coordinate system
	float l_X = aim_X - cannon.getX();
	float l_Y = cannon.getY() - aim_Y;

	auto angle = std::atan2(l_X, l_Y) * tools::getRadToDegrees();

	if (angle >= tools::getRightCannonRotLimit())
	{
		angle = tools::getRightCannonRotLimit();
	}

	if (angle <= tools::getLeftCannonRotLimit())
	{
		angle = tools::getLeftCannonRotLimit();
	}

	cannon.setRotation(angle);

	// create cannonball
	
}

// RENDER STATE
void Gun::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(stand);
	target.draw(cannon);
}