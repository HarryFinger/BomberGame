#include "GamePage.h"
#include "Tools.h"

GamePage::GamePage()
	: player(res_manager)
	, background(res_manager.getTexture(GameResourceManager::TypeTexture::BACKGROUND))
	, clock(res_manager.getTexture(GameResourceManager::TypeTexture::CLOCK))
	, timer("Hello Font", res_manager.getFont(GameResourceManager::TypeFont::FRUIT_DAYS))
{
	
	// debug
	circle.setFillColor(sf::Color::Blue);
	circle.setRadius(5.0f);
	circle.setOrigin(5.0f, 5.0f);

	//timer settings
	clock.CenterOrigin();
	clock.setScale(1.3f, 1.3f);
	clock.setPosition(70.0f, 80.0f);

	timer.setCharacterSize(36);
	timer.setFillColor(sf::Color::Yellow);
	timer.setOutlineColor(sf::Color::Red);
	timer.setOutlineThickness(2.0f);
	timer.setLetterSpacing(2.0f);
	timer.setOrigin(20.0f, 36 / 2.0f);
	timer.setPosition(71.0f, 75.0f);
}


// INPUT STATE
void GamePage::processInput(const sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			player.setLeftButtonClick(true);
		}
	}

	if (event.type == sf::Event::MouseMoved)
	{
		float mouse_x = static_cast<float>(event.mouseMove.x);
		float mouse_y = static_cast<float>(event.mouseMove.y);
		player.setCursorPosition(mouse_x, mouse_y);
	}
}

// UPDATE STATE
void GamePage::update(float delta_time)
{
	player.update(delta_time);

	time -= delta_time;
	timer.setString(std::to_string((uint32_t)time));
	if (time < 0.0f)
	{
		// to do
		this->task_type = TaskType::EXIT;
	}
}

// RENDER STATE
void GamePage::render(sf::RenderWindow& window)
{
	window.draw(background);
	window.draw(player);

	window.draw(clock);
	window.draw(timer);

	// debug
	//window.draw(circle);
}