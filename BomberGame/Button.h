#pragma once

#include "VisibleObject.h"

class Button final: public VisibleObject
{
public:
	enum class Type
	{
		START_EASY,
		START_NORMAL,
		START_HARD,
		EXIT,
		EMPTY,
	};

	Button(const sf::Texture& texture, Button::Type type);
	void update(float delta_time) override;
	
	Type getButtonType() const { return type_; }
	void setHover(bool hover) { on_hover = hover; };

private:
	void setScale(float scale);

private:
	const Type type_;
	const sf::Vector2f original_scale;

	bool on_hover = false;
};

