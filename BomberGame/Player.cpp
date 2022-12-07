#include "Player.h"
#include "Tools.h"


Player::Player(const GameResourceManager& res_manager)
	: res_manager(res_manager)
	, cursor(res_manager.getTexture(GameResourceManager::TypeTexture::AIM))
	, stand(res_manager.getTexture(GameResourceManager::TypeTexture::STAND))
	, cannon(res_manager.getTexture(GameResourceManager::TypeTexture::CANNON))
{
	cursor.CenterOrigin();
	cursor.setPosition(tools::getWindowWidth() / 2.0f, tools::getWindowHeight() / 2.0f);

	stand.CenterOrigin();
	stand.setPosition(tools::getWindowWidth() / 2.0f, 19.0f * tools::getWindowHeight() / 20.0f);

	cannon.setRelativeOrigin(0.5f, 0.69f);
	cannon.setPosition(tools::getWindowWidth() / 2.0f, 18.1f * tools::getWindowHeight() / 20.0f);
}

// UPDATE STATE
void Player::update(float delta_time)
{
	// todo
	// converting to new coordinate system
	float l_X = cursor.getX() - cannon.getX();
	float l_Y = cannon.getY() - cursor.getY();

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
	if (is_left_button_clicked)
	{
		Cannonball cannonball(res_manager.getTexture(GameResourceManager::TypeTexture::CANNONBALL));
		cannonball.CenterOrigin();
		cannonball.setPosition(cursor.getX(), cursor.getY());
		cannonball_list.push_back(cannonball);
		is_left_button_clicked = false;
	}

	// update cannonball timer or destroy
	for (auto it = cannonball_list.begin(); it != cannonball_list.end(); ++it)
	{
		it->update(delta_time);

		if (it->getLifeTime() > 2.0f)
		{
			it = cannonball_list.erase(it);
		}
	}
}

// RENDER STATE
void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(stand);
	target.draw(cannon);
	for (const auto& el : cannonball_list)
	{
		target.draw(el);
	}
	target.draw(cursor);
}