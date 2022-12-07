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

private:
	Type type_ = Type::EMPTY;

public:
	Button(const sf::Texture& texture, Button::Type type): VisibleObject(texture), type_(type){}
	
	Type getButtonType() const { return type_; }
};

