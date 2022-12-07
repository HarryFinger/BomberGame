#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Page
{
public:
	enum class TaskType
	{
		START,
		EXIT,

		NOTHING
	};
public:
	Page() {};
	
	TaskType getTaskType();
	virtual void processInput(const sf::Event& event) = 0;
	virtual void update(float delta_time) = 0;
	virtual void render(sf::RenderWindow& window) = 0;
protected:
	
	TaskType task_type = TaskType::NOTHING;
};