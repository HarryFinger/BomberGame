#pragma once

#include <SFML/Graphics.hpp>
#include "VisibleObject.h"

#include "GameResourceManager.h"

static constexpr float LEVEL_TIME = 60.0f;

class Timer : public sf::Drawable
{
public:
	Timer(const sf::Texture& clock_texture, const sf::Font& timer_font);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void update(float delta_time);
	bool IsTimerEnd();
private:
	void Flicker(float delta_time);

private:
	VisibleObject clock_picture;
	sf::Text clock_face;
	float time = LEVEL_TIME; // time before defeat
	bool do_once = false;

	float time_accumulator = 0.0f;
	float frequency = 7.0f;
};