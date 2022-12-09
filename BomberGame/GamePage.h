#pragma once

#include "Cannonball.h"
#include "GameResourceManager.h"
#include "Gun.h"
#include "Page.h"
#include "VisibleObject.h"
#include "Timer.h"

#include <SFML/Graphics.hpp>


class GamePage final : public Page
{

public:
	GamePage();

	void processInput(const sf::Event& event);
	void update(float delta_time);
	void render(sf::RenderWindow& window) override;

private:
	void CreateCannonball(sf::Vector2f for_vec, float speed);
	void CannonballUpdateOrDestroy(float delta_time);

	
private:
	GameResourceManager res_manager;

	Gun gun;
	Timer timer;

	VisibleObject cursor;
	VisibleObject background;

	std::list<Cannonball> cannonball_list;

	sf::CircleShape circle; // debug

	bool is_left_button_clicked = false;
};

