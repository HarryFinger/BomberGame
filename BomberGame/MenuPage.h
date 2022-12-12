#pragma once

#include "Page.h"
#include "MenuResourceManager.h"
#include "VisibleObject.h"
#include "Button.h"
#include "Cursor.h"

#include <list>

class MenuPage final : public Page
{
public:
	MenuPage();
	void processInput(const sf::Event& event) override;
	void update(float delta_time) override;
	void render(sf::RenderWindow& window) override;

private:
	MenuResourceManager res_manager;

	std::list<VisibleObject> object_list;
	std::list<Button> button_list;
	Cursor cursor;
	bool is_left_button_clicked = false;
	
private:
	Button* getButtonOnHover();
};

