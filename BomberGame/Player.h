#pragma once

#include <SFML/Graphics.hpp>
#include <list>

#include "Cannonball.h"
#include "GameResourceManager.h"
#include "VisibleObject.h"

class Player final: public sf::Drawable
{
public:
	Player(const GameResourceManager& res_manager);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void update(float delta_time);

	void setCursorPosition(float X, float Y) { cursor.setPosition(X, Y); };
	void setLeftButtonClick(bool val) { is_left_button_clicked = val; }

private:
	GameResourceManager res_manager;

	VisibleObject cursor;
	VisibleObject stand;
	VisibleObject cannon;

	std::list<Cannonball> cannonball_list;

	bool is_left_button_clicked = false;
	sf::Vector2f cannon_forward_vector{ 0.0f, 0.0f };
};

