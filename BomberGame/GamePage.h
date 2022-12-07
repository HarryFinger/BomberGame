#pragma once

#include "Page.h"
#include "VisibleObject.h"
#include "GameResourceManager.h"
#include "Player.h"

#include <SFML/Graphics.hpp>

constexpr float LEVEL_TIME = 13.0f;

class GamePage final : public Page
{

public:
	GamePage();

	void processInput(const sf::Event& event);
	void update(float delta_time);
	void render(sf::RenderWindow& window) override;
	
private:
	GameResourceManager res_manager;

	Player player;

	VisibleObject background;
	VisibleObject clock;
	sf::Text timer;	

	float time = LEVEL_TIME; // time before defeat

	sf::CircleShape circle; // debug

	bool is_left_button_clicked = false;
};

