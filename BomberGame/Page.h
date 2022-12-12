#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Page
{
public:
	enum class TargetType
	{
		MENU,
		GAME,
		EXIT,
		IDLE,
	};

	TargetType getTargetType() const;
	virtual void processInput(const sf::Event& event) = 0;
	virtual void update(float delta_time) = 0;
	virtual void render(sf::RenderWindow& window) = 0;

protected:
	TargetType target_type = TargetType::IDLE;
};