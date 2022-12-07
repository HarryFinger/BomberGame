#pragma once
#include "Page.h"


class GamePage final : public Page
{

public:

	void processInput(const sf::Event& event);
	void update(float delta_time);
	void render(sf::RenderWindow& window) override;
	
};

