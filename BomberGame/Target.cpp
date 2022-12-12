#include "Target.h"
#include "Tools.h"

namespace
{
	constexpr float BASE_SPEED = 200.0f;
}

Target::Target(const sf::Texture& texture, Type type, sf::Vector2f for_vec, sf::Vector2f position): VisibleObject(texture), type_(type), forward_vector(for_vec)
{
	sprite_.setTextureRect(sf::IntRect(0,0,80,80));
	switch (type_)
	{
	case Target::Type::GREEN:
	{
		sprite_.setColor(sf::Color::Green);
		this->CenterOrigin();
		sprite_.setScale(0.85f, 0.85f);
		speed = BASE_SPEED + 100.0f;
	}
		break;
	case Target::Type::YELLOW:
	{
		sprite_.setColor(sf::Color::Yellow);
		this->CenterOrigin();
		sprite_.setScale(1.0f, 1.0f);		
		speed = BASE_SPEED;

	}
		break;
	case Target::Type::RED:
	{
		sprite_.setColor(sf::Color::Magenta);
		this->CenterOrigin();
		sprite_.setScale(1.15f, 1.15f);
		speed = BASE_SPEED - 100.0f;
	}
		break;
	}

	radius = sprite_.getGlobalBounds().width / 2.f;

	sprite_.setPosition(position);
}

void Target::update(float delta_time)
{
	if (hit_points <= 66.f && hit_points > 33.f)
	{
		sprite_.setTextureRect(sf::IntRect(80, 0, 80, 80));
	}
	if (hit_points <= 33.f)
	{
		sprite_.setTextureRect(sf::IntRect(160, 0, 80, 80));
	}

	if (sprite_.getPosition().x < 0.f + radius)
	{
		sprite_.setPosition(sf::Vector2f(0.f + radius, sprite_.getPosition().y));
		sf::Vector2f norm_vec(1.f, 0.f);
		forward_vector = tools::CalcNormalizeReflectionVector(forward_vector, norm_vec);
	}

	if (sprite_.getPosition().x > tools::getWindowWidth() - radius)
	{
		sprite_.setPosition(sf::Vector2f(tools::getWindowWidth() - radius, sprite_.getPosition().y));
		sf::Vector2f norm_vec(-1.f, 0.f);
		forward_vector = tools::CalcNormalizeReflectionVector(forward_vector, norm_vec);
	}

	if (sprite_.getPosition().y < 0.f + radius)
	{
		sprite_.setPosition(sf::Vector2f(sprite_.getPosition().x, 0.f + radius));
		sf::Vector2f norm_vec(0.f, 1.f);
		forward_vector = tools::CalcNormalizeReflectionVector(forward_vector, norm_vec);
	}

	if (sprite_.getPosition().y > tools::getWindowHeight() - radius)
	{
		sprite_.setPosition(sf::Vector2f(sprite_.getPosition().x, tools::getWindowHeight() - radius));
		sf::Vector2f norm_vec(0.f, -1.f);
		forward_vector = tools::CalcNormalizeReflectionVector(forward_vector, norm_vec);
	}


	float dx = forward_vector.x * speed * delta_time;
	float dy = forward_vector.y * speed * delta_time;

	
	float tmpX = this->getPosition().x + dx;
	float tmpY = this->getPosition().y + dy;

	sprite_.setPosition(sf::Vector2f(tmpX, tmpY));

	
}

bool Target::IsDead()
{
	return (hit_points < 0.0f);
}

void Target::DealingDamage()
{
	switch (type_)
	{
	case Target::Type::GREEN:
	{
		hit_points -= 101.f;
	}
		break;
	case Target::Type::YELLOW:
	{
		hit_points -= 67.f;
	}
		break;
	case Target::Type::RED:
	{
		hit_points -= 34.f;
	}
		break;
	
	}
}
