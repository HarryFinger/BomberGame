#include "Gun.h"

#include "Tools.h"

#include<iostream>

// todo constexpr
namespace
{
	const float max_forward_vec_y = -std::cos(tools::getCannonRotationLimit()* tools::DegreesToRadian());
	constexpr float min_forward_vec_y = -1.0f;
	const float max_forward_vec_x = std::sin(tools::getCannonRotationLimit() * tools::DegreesToRadian());
	const float min_forward_vec_x = -std::sin(tools::getCannonRotationLimit() * tools::DegreesToRadian());

	const sf::Color red(192, 105, 105, 255);
}

Gun::Gun(const sf::Texture& cannon_texture, const sf::Texture& stand_texture, const sf::Texture& shield_texture):
	  cannon(cannon_texture)
	, stand(stand_texture)
	, shield(shield_texture)
{
	stand.CenterOrigin();
	stand.setPosition(sf::Vector2f(tools::getWindowWidth() / 2.0f, 19.0f * tools::getWindowHeight() / 20.0f));

	cannon.setRelativeOrigin(0.5f, 0.69f);
	cannon.setPosition(sf::Vector2f(tools::getWindowWidth() / 2.0f, 18.1f * tools::getWindowHeight() / 20.0f));

	shield.CenterOrigin();
	shield.setPosition(sf::Vector2f(tools::getWindowWidth() / 2.0f, 18.2f * tools::getWindowHeight() / 20.0f));

	radius = shield.getCollisionBox().width / 2.f;
	original_color = cannon.getColor();
}

// UPDATE STATE
void Gun::update(float delta_time)
{
	if (cooldown > 0.f)
	{
		cooldown -= delta_time;
	}

	forward_vector = tools::NormalizeVector(sf::Vector2f(aim_position.x - cannon.getPosition().x, aim_position.y - cannon.getPosition().y));

	if (forward_vector.y > max_forward_vec_y)
	{
		forward_vector.y = max_forward_vec_y;
		forward_vector.x = (forward_vector.x > max_forward_vec_x ? max_forward_vec_x : min_forward_vec_x);
	}

	// sf::Vector2f(-1.0f, 0.f) is unit vector pointing left
	float alpha = std::acos(tools::DotProduct(sf::Vector2f(-1.0f, 0.0f), forward_vector)) * tools::RadianToDegrees() - 90.f;
	cannon.setRotation(alpha);

	//set shield hp 
	sf::Uint8 hp_visibility;
	if (shield_hp < 0.f)
	{
		hp_visibility = 0;
	}
	else
	{
		hp_visibility = (sf::Uint8)((shield_hp / 100.f) * 255);
	}

	shield.setColor(sf::Color(255, 255, 255, hp_visibility));
	IndicateCooldown();
}

void Gun::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(stand);
	target.draw(cannon);
	target.draw(shield);
}

void Gun::setCreateCannonballFunction(CreateCannonballFunction create_cannonball_func)
{
	create_cannonball_function = create_cannonball_func;
}

bool Gun::IsDead()
{
	return (gun_hp < 0.f);
}

void Gun::DealingDamage(float damage)
{
	if (shield_hp > 0.f)
	{
		shield_hp -= damage;
	}
	else
	{
		gun_hp -= damage;
	}
}

// RENDER STATE
void Gun::TryToShoot()
{
	if (cooldown > 0.f)
	{
		return;
	}

	create_cannonball_function();

	cooldown = time_between_shots;
}

void Gun::IndicateCooldown()
{
	if (cooldown > 0.f)
	{
		stand.setColor(red);
		cannon.setColor(red);
	}
	else
	{
		stand.setColor(original_color);
		cannon.setColor(original_color);
	}
}