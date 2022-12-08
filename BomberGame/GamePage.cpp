#include "GamePage.h"
#include "Tools.h"

GamePage::GamePage()
	: gun(res_manager.getTexture(GameResourceManager::TypeTexture::CANNON),
		res_manager.getTexture(GameResourceManager::TypeTexture::STAND))
	, timer(res_manager.getTexture(GameResourceManager::TypeTexture::CLOCK),
		res_manager.getFont(GameResourceManager::TypeFont::FRUIT_DAYS))
	, cursor(res_manager.getTexture(GameResourceManager::TypeTexture::AIM))
	, background(res_manager.getTexture(GameResourceManager::TypeTexture::BACKGROUND))
	
{
	// cursor
	cursor.CenterOrigin();
	cursor.setPosition(tools::getWindowWidth() / 2.0f, tools::getWindowHeight() / 2.0f);

	// debug
	circle.setFillColor(sf::Color::Blue);
	circle.setRadius(5.0f);
	circle.setOrigin(5.0f, 5.0f);
}


// INPUT STATE
void GamePage::processInput(const sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			is_left_button_clicked = true; // fire
		}
	}

	if (event.type == sf::Event::MouseMoved)
	{
		float mouse_x = static_cast<float>(event.mouseMove.x);
		float mouse_y = static_cast<float>(event.mouseMove.y);
		cursor.setPosition(mouse_x, mouse_y);
		gun.updateAimCoordinate(mouse_x, mouse_y);
	}
}

// UPDATE STATE
void GamePage::update(float delta_time)
{
	gun.update(delta_time);
	timer.update(delta_time);

	if (timer.IsTimerEnd())
	{
		// todo
		this->task_type = TaskType::EXIT;
	}

	if (is_left_button_clicked)
	{
		CreateCannonball();
	}

	CannonballUpdateOrDestroy(delta_time);
}

// RENDER STATE
void GamePage::render(sf::RenderWindow& window)
{
	window.draw(background);
	window.draw(gun);

	for (const auto& cball_el : cannonball_list)
	{
		window.draw(cball_el);
	}

	window.draw(timer);
	window.draw(cursor);
	
	// debug
	//window.draw(circle);
}

void GamePage::CreateCannonball()
{
	Cannonball cannonball(res_manager.getTexture(GameResourceManager::TypeTexture::CANNONBALL));
	cannonball.CenterOrigin();
	cannonball.setPosition(cursor.getX(), cursor.getY());
	cannonball_list.push_back(cannonball);
	is_left_button_clicked = false;
}

void GamePage::CannonballUpdateOrDestroy(float delta_time)
{
	for (auto it = cannonball_list.begin(); it != cannonball_list.end(); )
	{
		it->update(delta_time);

		if (it->getLifeTime() > 2.0f)
		{
			it = cannonball_list.erase(it);
		}
		else
		{
			++it;
		}
	}
}
