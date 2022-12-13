#include "Gun.h"

#include "Tools.h"

namespace
{
	const auto max_forward_vec_y = -std::cos(tools::getCannonRotationLimit()* tools::DegreesToRadian());
	constexpr auto min_forward_vec_y = -1.0f;
	const auto max_forward_vec_x = std::sin(tools::getCannonRotationLimit() * tools::DegreesToRadian());
	const auto min_forward_vec_x = -std::sin(tools::getCannonRotationLimit() * tools::DegreesToRadian());

	const sf::Color RED{ 192, 105, 105, 255 };
}

Gun::Gun(const sf::Texture& cannon_texture, const sf::Texture& stand_texture, const sf::Texture& shield_texture)
	: cannon(cannon_texture)
	, stand(stand_texture)
	, shield(shield_texture)
	, original_color(cannon.getColor())
	, radius(0.5f * shield.getCollisionBox().width)
{
	stand.CenterOrigin();
	stand.setPosition({ 0.5f * tools::getWindowWidth(), 19.0f * tools::getWindowHeight() / 20.0f });

	cannon.setRelativeOrigin({ 0.5f, 0.69f });
	cannon.setPosition({ 0.5f *  tools::getWindowWidth(), 18.1f * tools::getWindowHeight() / 20.0f });

	shield.CenterOrigin();
	shield.setPosition({ 0.5f *  tools::getWindowWidth(), 18.2f * tools::getWindowHeight() / 20.0f });
}

// UPDATE STATE
void Gun::update(float delta_time)
{
	if (cooldown > 0.0f)
	{
		cooldown -= delta_time;
		if (cooldown <= 0.0f)
		{
			IndicateCooldown();
		}
	}

	forward_vector = tools::NormalizeVector({ aim_position.x - cannon.getPosition().x, aim_position.y - cannon.getPosition().y });

	if (forward_vector.y > max_forward_vec_y)
	{
		forward_vector.y = max_forward_vec_y;
		forward_vector.x = (forward_vector.x > max_forward_vec_x ? max_forward_vec_x : min_forward_vec_x);
	}

	// sf::Vector2f(-1.0f, 0.f) is unit vector pointing left
	const auto alpha = std::acos(-forward_vector.x) * tools::RadianToDegrees() - 90.f;
	cannon.setRotation(alpha);

	// set shield hp 
	sf::Uint8 hp_visibility;
	if (shield_hp <= 0)
	{
		hp_visibility = 0;
	}
	else
	{
		hp_visibility = (sf::Uint8)((shield_hp / 100.f) * 255);
	}
	shield.setColor({ 255, 255, 255, hp_visibility });
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

bool Gun::IsDead() const
{
	return gun_hp < 0;
}

void Gun::DealingDamage(int32_t damage)
{
	if (shield_hp > 0)
	{
		shield_hp -= damage;
	}
	else
	{
		gun_hp -= damage;
	}
}

void Gun::TryToShoot()
{
	if (cooldown > 0.0f)
	{
		return;
	}

	create_cannonball_function();

	cooldown = time_between_shots;
	IndicateCooldown();
}

void Gun::IndicateCooldown()
{
	if (cooldown > 0.0f)
	{
		stand.setColor(RED);
		cannon.setColor(RED);
	}
	else
	{
		stand.setColor(original_color);
		cannon.setColor(original_color);
	}
}