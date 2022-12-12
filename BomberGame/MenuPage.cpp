#include "MenuPage.h"
#include "Manager.h"
#include "Tools.h"

#include <iostream>
#include <string>


MenuPage::MenuPage(): cursor(res_manager.getTexture(MenuResourceManager::TypeTexture::CURSOR))
{
	cursor.setPosition(sf::Vector2f(tools::getWindowWidth() / 2.0f, tools::getWindowHeight() / 2.0f));
	cursor.StartFlicker();

	VisibleObject background(res_manager.getTexture(MenuResourceManager::TypeTexture::BACKGROUND));
	object_list.push_back(background);

	Button button_start(res_manager.getTexture(MenuResourceManager::TypeTexture::BUTTON_1), Button::Type::START);
	button_start.CenterOrigin();
	button_start.setPosition(sf::Vector2f(tools::getWindowWidth() / 2.0f, tools::getWindowHeight() / 3.0f));
	button_list.push_back(button_start);

	Button button_exit(res_manager.getTexture(MenuResourceManager::TypeTexture::BUTTON_3), Button::Type::EXIT);
	button_exit.CenterOrigin();
	button_exit.setPosition(sf::Vector2f(tools::getWindowWidth() / 2.0f, 2.0f * tools::getWindowHeight() / 3.0f));
	button_list.push_back(button_exit);

}

void MenuPage::processInput(const sf::Event& event)
{
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
				case Button::Type::START:
					this->target_type = TargetType::GAME;
					break;

				case Button::Type::EXIT:
					this->target_type = TargetType::EXIT;
					break;

				case Button::Type::EMPTY:
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
