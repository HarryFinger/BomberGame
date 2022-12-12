#include "Timer.h"
#include "Tools.h"

Timer::Timer(const sf::Texture& clock_texture, const sf::Font& timer_font):
	clock_picture(clock_texture)
	, clock_face("", timer_font)
{
	clock_picture.CenterOrigin();
	clock_picture.setPosition(sf::Vector2f(tools::getWindowWidth() - 75.0f, tools::getWindowHeight() - 75.0f));

	clock_face.setCharacterSize(38);
	clock_face.setFillColor(sf::Color::Yellow);
	clock_face.setOutlineColor(sf::Color::Red);
	clock_face.setOutlineThickness(2.0f);
	clock_face.setLetterSpacing(2.0f);
	clock_face.setPosition(tools::getWindowWidth() - 97.0f, tools::getWindowHeight() - 100.0f);
}

void Timer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(clock_picture);
	target.draw(clock_face);
}

void Timer::update(float delta_time)
{
	time -= delta_time;

	if (time < 10.0f)
	{
		Flicker(delta_time);
		if (!do_once)
		{
			clock_face.setPosition(clock_face.getPosition() + sf::Vector2f(6.f, 0.f));
			do_once = true;
		}
	}
	clock_face.setString(std::to_string((uint32_t)time));
}

void Timer::Flicker(float delta_time)
{
	time_accumulator += delta_time; //potential inf
	float scale = std::sin(time_accumulator * frequency) / 10 + 1.f;
	clock_picture.setScale(scale, scale);
}

bool Timer::IsTimerEnd()
{
	return (time < 0.0f);
}