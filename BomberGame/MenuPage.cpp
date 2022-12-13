#include "MenuPage.h"
#include "Manager.h"
#include "Tools.h"

#include <iostream>
#include <string>

namespace
{
	// number of target that will spawn in game
	constexpr uint32_t EASY_DIFFICULTY = 5;
	constexpr uint32_t NORMAL_DIFFICULTY = 7;
	constexpr uint32_t HARD_DIFFICULTY = 9;

} // namespace

MenuPage::MenuPage(): cursor(res_manager.getTexture(MenuResourceManager::TypeTexture::CURSOR))
{
	sf::Mouse mouse;
	cursor.setPosition((sf::Vector2f)mouse.getPosition());
	cursor.StartFlicker();

	VisibleObject background(res_manager.getTexture(MenuResourceManager::TypeTexture::BACKGROUND));
	object_list.push_back(background);

	Button button_easy(res_manager.getTexture(MenuResourceManager::TypeTexture::BUTTON_EASY), Button::Type::START_EASY);
	button_easy.CenterOrigin();
	button_easy.setPosition({ 3.0f * tools::getWindowWidth() / 16.0f, 2.0f * tools::getWindowHeight() / 5.0f });
	button_list.push_back(button_easy);

	Button button_normal(res_manager.getTexture(MenuResourceManager::TypeTexture::BUTTON_NORMAL), Button::Type::START_NORMAL);
	button_normal.CenterOrigin();
	button_normal.setPosition({ 8.0f * tools::getWindowWidth() / 16.0f, tools::getWindowHeight() / 5.0f });
	button_list.push_back(button_normal);

	Button button_hard(res_manager.getTexture(MenuResourceManager::TypeTexture::BUTTON_HARD), Button::Type::START_HARD);
	button_hard.CenterOrigin();
	button_hard.setPosition({ 13.0f * tools::getWindowWidth() / 16.0f, 2.0f * tools::getWindowHeight() / 5.0f });
	button_list.push_back(button_hard);

	Button button_exit(res_manager.getTexture(MenuResourceManager::TypeTexture::BUTTON_EXIT), Button::Type::EXIT);
	button_exit.CenterOrigin();
	button_exit.setPosition({ tools::getWindowWidth() / 2.0f, 4.0f * tools::getWindowHeight() / 5.0f });
	button_list.push_back(button_exit);

}

void MenuPage::processInput(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			target_type = Page::TargetType::EXIT;
			return;
		}
	}
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			is_left_button_clicked = true;
		}
	}

	if (event.type == sf::Event::MouseMoved)
	{
		const auto mouse_x = static_cast<float>(event.mouseMove.x);
		const auto mouse_y = static_cast<float>(event.mouseMove.y);
		cursor.setPosition({ mouse_x, mouse_y });
	}
}

void MenuPage::update(float delta_time)
{
	auto button = getButtonOnHover();

	if (is_left_button_clicked)
	{
		if (button != nullptr)
		{
			switch (button->getButtonType())
			{
				case Button::Type::START_EASY:
				this->target_type = TargetType::GAME;
				game_difficulty = EASY_DIFFICULTY;
				break;

				case Button::Type::START_NORMAL:
				this->target_type = TargetType::GAME;
				game_difficulty = NORMAL_DIFFICULTY;
				break;

				case Button::Type::START_HARD:
				this->target_type = TargetType::GAME;
				game_difficulty = HARD_DIFFICULTY;
				break;

				case Button::Type::EXIT:
					this->target_type = TargetType::EXIT;
				break;

				case Button::Type::EMPTY:
				break;

				default:
				break;
			}
		}
	}

	for (auto& button: button_list)
	{
		button.update(delta_time);
	}

	cursor.update(delta_time);

	is_left_button_clicked = false;
}

void MenuPage::render(sf::RenderWindow& window)
{
	for (const auto& obj : object_list)
	{
		window.draw(obj);
	}

	for (const auto& button : button_list)
	{
		window.draw(button);
	}

	window.draw(cursor);
}

Button* MenuPage::getButtonOnHover()
{
	for (auto& button : button_list)
	{
		if (button.IsContains(cursor.getPosition()))
		{
			button.setHover(true);
			return &button;
		}
	}
	return nullptr;
}
