#include "GamePage.h"
#include "MenuPage.h"
#include "Manager.h"

#include <iostream>

Manager::Manager(sf::RenderWindow* pwindow_) : pwindow(pwindow_)
{
	current_state = std::make_unique<MenuPage>();
	//current_state = std::make_unique<GamePage>();
}

void Manager::processInput(const sf::Event& event)
{
	current_state->processInput(event);
}

void Manager::update(float delta_time)
{
	switch (current_state->getTargetType())
	{
		case Page::TargetType::MENU:
			current_state = std::make_unique<MenuPage>();
		break;
		case Page::TargetType::GAME:
			current_state = std::make_unique<GamePage>();
		break;
		case Page::TargetType::EXIT:
			pwindow->close();
		break;

		default:
		break;
	}
	
	current_state->update(delta_time);
}

void Manager::render()
{
	current_state->render(*pwindow);
}
