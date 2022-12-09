#pragma once

#include <SFML/Graphics.hpp>

namespace tools
{
	uint32_t getWindowWidth();
	uint32_t getWindowHeight();
	float getFPS();
	float getRadToDegrees();
	float getCanRotLimit();

	// collision part
	float DotProduct(sf::Vector2f a, sf::Vector2f b);
	float DistanceBetweenTwoObjects(sf::Vector2f a, sf::Vector2f b);
	sf::Vector2f NormalizeVector(sf::Vector2f vec);
	sf::Vector2f CalcNormalizeReflectionVector(sf::Vector2f inc_vec, sf::Vector2f normal_vec);

	template<typename T>
	constexpr T Clamp(const T& v, const T& from, const T& to)
	{
		return (v < from) ? from : ((v > to) ? to : v);
	}
} // namespace tools
