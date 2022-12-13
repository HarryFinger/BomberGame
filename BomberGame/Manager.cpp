#include "GamePage.h"
#include "MenuPage.h"
#include "Manager.h"

Manager::Manager(sf::RenderWindow* pwindow_) : pwindow(pwindow_)
{
	current_state = std::make_unique<MenuPage>();
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
		{
			MenuPage* p_page = dynamic_cast<MenuPage*>(current_state.get());
			if (p_page != nullptr)
			{
				current_difficulty = p_page->getGameDifficulty();
			}
			else
			{
				current_difficulty = 7;
			}
			current_state = std::make_unique<GamePage>(current_difficulty);
		}
		break;

	case Page::TargetType::RESTART:
		current_state = std::make_unique<GamePage>(current_difficulty);
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
