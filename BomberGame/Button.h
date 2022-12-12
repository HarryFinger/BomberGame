#pragma once
#include "VisibleObject.h"

class Button final: public VisibleObject
{
public:
	enum class Type
	{
		START,
		EXIT,
		EMPTY
	};

	Button(const sf::Texture& texture, Button::Type type);
	void update(float delta_time);

	
	Type getButtonType() const { return type_; }
	void setOnHover() { on_hover = true; };

private:
	void ScaleUp();
	void ResetScale();
private:

	Type type_ = Type::EMPTY;
	sf::Vector2f original_scale;
	bool on_hover = false;
};

