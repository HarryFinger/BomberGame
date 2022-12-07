#pragma once

#include "Page.h"

#include <SFML/Graphics.hpp>

class Manager final
{
private:
	std::unique_ptr<Page> current_state;
	sf::RenderWindow* pwindow;

public:
	Manager(sf::RenderWindow* window);
	void processInput(const sf::Event& event);
	void update(float delta_time);
	void render();
};

