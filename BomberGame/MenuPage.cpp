#include "MenuPage.h"
#include "Manager.h"
#include "Tools.h"

#include <iostream>
#include <string>


MenuPage::MenuPage(): cursor(res_manager.getTexture(MenuResourceManager::TypeTexture::CURSOR))
{
	cursor.setPosition(tools::getWindowWidth() / 2.0f, tools::getWindowHeight() / 2.0f);

	VisibleObject background(res_manager.getTexture(MenuResourceManager::TypeTexture::BACKGROUND));
	object_list.push_back(background);

	Button button1(res_manager.getTexture(MenuResourceManager::TypeTexture::BUTTON_1), Button::Type::START);
	button1.CenterOrigin();
	button1.setPosition(tools::getWindowWidth() / 2.0f, tools::getWindowHeight() / 3.0f);
	button_list.push_back(button1);

	Button button3(res_manager.getTexture(MenuResourceManager::TypeTexture::BUTTON_3), Button::Type::EXIT);
	button3.CenterOrigin();
	button3.setPosition(tools::getWindowWidth() / 2.0f, 2.0f * tools::getWindowHeight() / 3.0f);
	button_list.push_back(button3);

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
		float mouse_x = static_cast<float>(event.mouseMove.x);
		float mouse_y = static_cast<float>(event.mouseMove.y);
		cursor.setPosition(mouse_x, mouse_y);
	}
}

void MenuPage::update(float delta_time)
{
	if (is_left_button_clicked)
	{
		auto button = PressedButton();
		if (button != nullptr)
		{
			switch (button->getButtonType())
			{
				case Button::Type::START:
					this->task_type = TaskType::START;
					break;

				case Button::Type::EXIT:
					this->task_type = TaskType::EXIT;
					break;

				case Button::Type::EMPTY:
					break;
			}
		}
	}
		
	is_left_button_clicked = false;
}

void MenuPage::render(sf::RenderWindow& window)
{
	for (const auto&  obj_el : object_list)
		window.draw(obj_el);

	for (const auto& button_el : button_list)
		window.draw(button_el);

	window.draw(cursor);
}


Button* MenuPage::PressedButton()
{
	for (auto& button_el : button_list)
	{
		if (button_el.IsContains(cursor.getX(), cursor.getY()))
		{
			return &button_el;
		}
	}
	return nullptr;
}
