#pragma once
#include <SFML/Graphics.hpp>

#include <memory>
#include <iostream>

#include "Page.h"
#include "GamePage.h"
#include "MenuPage.h"


class Manager final
{
private:
	std::unique_ptr<Page> current_state;
	sf::RenderWindow* window;

public:
	Manager();
	void processInput(const sf::Event& event);
	void update(float delta_time);
	void render(sf::RenderWindow& window);
};

