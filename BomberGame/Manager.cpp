#include "Manager.h"
#include "MenuPage.h"
#include <iostream>

Manager::Manager()
{
	current_state = std::make_unique<MenuPage>();
	
}

void Manager::processInput(const sf::Event& event)
{
	current_state->processInput(event);
}

void Manager::update(float delta_time)
{
	

	current_state->update(delta_time);
}
void Manager::render(sf::RenderWindow& window)
{
	if (current_state->getTaskType() == Page::TaskType::EXIT)
		window.close();

	current_state->render(window);
}
