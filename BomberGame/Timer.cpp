#include "Timer.h"
#include "Tools.h"

Timer::Timer(const sf::Texture& clock_texture, const sf::Font& timer_font):
	  clock(clock_texture)
	, timer("", timer_font)
{
	clock.CenterOrigin();
	clock.setScale(1.35f, 1.35f);
	clock.setPosition(sf::Vector2f(tools::getWindowWidth() - 75.0f, tools::getWindowHeight() - 75.0f));

	timer.setCharacterSize(38);
	timer.setFillColor(sf::Color::Yellow);
	timer.setOutlineColor(sf::Color::Red);
	timer.setOutlineThickness(2.0f);
	timer.setLetterSpacing(2.0f);
	// timer.setOrigin(20.0f, 36 / 2.0f);
	timer.setPosition(tools::getWindowWidth() - 100.0f, tools::getWindowHeight() - 100.0f);
}

void Timer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(clock);
	target.draw(timer);
}

void Timer::update(float delta_time)
{
	time -= delta_time;
	timer.setString(std::to_string((uint32_t)time));
}

bool Timer::IsTimerEnd()
{
	return (time < 0.0f);
}