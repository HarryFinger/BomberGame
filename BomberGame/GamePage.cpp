#include "GamePage.h"
#include "Tools.h"

namespace 
{
	const float CANNONBALL_SPEED = 300.0f;
}

GamePage::GamePage()
	: gun( res_manager.getTexture(GameResourceManager::TypeTexture::CANNON)
		, res_manager.getTexture(GameResourceManager::TypeTexture::STAND)
		, res_manager.getTexture(GameResourceManager::TypeTexture::SHIELD) )
	, timer(res_manager.getTexture(GameResourceManager::TypeTexture::CLOCK),
		res_manager.getFont(GameResourceManager::TypeFont::FRUIT_DAYS))
	, cursor(res_manager.getTexture(GameResourceManager::TypeTexture::AIM))
	, background(res_manager.getTexture(GameResourceManager::TypeTexture::BACKGROUND))
	, win(res_manager.getTexture(GameResourceManager::TypeTexture::WIN))
	, lose(res_manager.getTexture(GameResourceManager::TypeTexture::LOSE))

{
	task_type = TaskType::NOTHING;

	lose.CenterOrigin();
	lose.setPosition(sf::Vector2f(tools::getWindowWidth() / 2.0f, tools::getWindowHeight() / 2.0f - 100.f));
	win.CenterOrigin();
	win.setPosition(sf::Vector2f(tools::getWindowWidth() / 2.0f, tools::getWindowHeight() / 2.0f - 100.f));

	// cursor
	cursor.CenterOrigin();
	cursor.setPosition(sf::Vector2f(tools::getWindowWidth() / 2.0f, tools::getWindowHeight() / 2.0f));
	cursor.StartFlicker();

	gun.setCreateCannonballFunction([this]() {
		CreateCannonball(gun.getForwardVercor(), CANNONBALL_SPEED);
	});

	// target spawner
	for (size_t i = 0; i < 5; i++)
	{
		CreateTarget();
	}
}


// INPUT STATE
void GamePage::processInput(const sf::Event& event)
{
	if (task_type == GamePage::TaskType::LOSE || task_type == GamePage::TaskType::WIN)
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			task_type = GamePage::TaskType::EXIT;
			return;
		}
		if (event.type == sf::Event::EventType::KeyPressed || event.type == event.MouseButtonPressed)
		{
			task_type = GamePage::TaskType::RESTART;
			return;
		}
	}

	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			gun.TryToShoot();
		}
	}

	if (event.type == sf::Event::MouseMoved)
	{
		float mouse_x = static_cast<float>(event.mouseMove.x);
		float mouse_y = static_cast<float>(event.mouseMove.y);
		sf::Vector2f mouse_vec(mouse_x, mouse_y);
		cursor.setPosition(mouse_vec);
		gun.UpdateAimPosition(mouse_vec);
	}
}

// UPDATE STATE
void GamePage::update(float delta_time)
{
	if (timer.IsTimerEnd() || gun.IsDead())
	{
		this->task_type = TaskType::LOSE;
	}
	if (target_list.size() == 0)
	{
		this->task_type = TaskType::WIN;
	}

	if(this->task_type == TaskType::NOTHING)
	{
		// target and cannonball collisions
		for (auto cannonball_it = cannonball_list.begin(), cannonball_it_last = cannonball_list.end(); cannonball_it != cannonball_it_last; ++cannonball_it)
		{
			for (auto target_it = target_list.begin(), target_it_last = target_list.end(); target_it != target_it_last; ++target_it)
			{
				float distance = tools::DistanceBetweenTwoObjects(cannonball_it->getPosition(), target_it->getPosition());
				{
					if (distance <= cannonball_it->getRadius() + target_it->getRadius()) // collision happens
					{
						cannonball_it = cannonball_list.erase(cannonball_it);
						target_it->DealingDamage();
						if (target_it->IsDead())
						{
							target_it = target_list.erase(target_it);
						}
						if (cannonball_it == cannonball_it_last || target_it == target_it_last)
						{
							goto END;
						}
					}
				}
			}
		}
	END:

		// shield and target collision
		for (auto& target : target_list)
		{
			float distance = tools::DistanceBetweenTwoObjects(target.getPosition(), gun.getShieldPosition());

			if (distance <= target.getRadius() + gun.getShieldRadius()) // collision happens
			{
				sf::Vector2f new_vec(target.getPosition() - gun.getShieldPosition());
				sf::Vector2f norm_new_vec = tools::NormalizeVector(new_vec);
				target.ChangeForwardVector(norm_new_vec);
				gun.DealingDamage(26.0f);
			}
		}

		// update collision between targets
		if (target_list.size() > 1)
		{
			for (auto ball_it_first = target_list.begin(), it_last = --target_list.end(); ball_it_first != it_last; ++ball_it_first)
			{
				auto ball_it_second = ball_it_first;
				++ball_it_second;

				for (auto it_end = target_list.end(); ball_it_second != it_end; ++ball_it_second)
				{
					float distance = tools::DistanceBetweenTwoObjects(ball_it_first->getPosition(), ball_it_second->getPosition());

					if (distance <= (ball_it_first->getRadius() + ball_it_second->getRadius())) // collision happens
					{
						sf::Vector2f new_vec(ball_it_first->getPosition() - ball_it_second->getPosition());
						sf::Vector2f norm_new_vec = tools::NormalizeVector(new_vec);
						ball_it_first->ChangeForwardVector(norm_new_vec);

						norm_new_vec *= -1.f;
						ball_it_second->ChangeForwardVector(norm_new_vec);
					}
				}
			}
		}

		cursor.update(delta_time);
		gun.update(delta_time);
		timer.update(delta_time);

		for (auto& target : target_list)
		{
			target.update(delta_time);
		}
		
		// cannonball update
		for (auto it = cannonball_list.begin(); it != cannonball_list.end(); )
		{
			it->update(delta_time);
			if (it->IsDead())
			{
				it = cannonball_list.erase(it);
			}
			else
			{
				++it;
			}
		}
	}
}

// RENDER STATE
void GamePage::render(sf::RenderWindow& window)
{
	window.draw(background);
	window.draw(gun);

	for (const auto& target : target_list)
	{
		window.draw(target);
	}

	for (const auto& cannonball : cannonball_list)
	{
		window.draw(cannonball);
	}


	window.draw(timer);
	window.draw(cursor);
	
	if (this->task_type == GamePage::TaskType::WIN)
	{
		window.draw(win);
	}
	if (this->task_type == GamePage::TaskType::LOSE)
	{
		window.draw(lose);

	}
}

void GamePage::CreateCannonball(sf::Vector2f for_vec, float speed)
{
	sf::Vector2f cannon_end = gun.getPosition() + gun.getForwardVercor()* 90.0f; // barrel length
	Cannonball cannonball(res_manager.getTexture(GameResourceManager::TypeTexture::CANNONBALL), cannon_end, for_vec, speed);
	cannonball_list.push_back(cannonball);
}


void GamePage::CreateTarget()
{
	Target::Type type = (Target::Type)(rand() % 3);
	float random_forward_vector_y = -1.f * static_cast<float>(std::rand()) / RAND_MAX;
	float random_forward_vector_x = std::sqrt(1 - random_forward_vector_y* random_forward_vector_y);
	float randX = rand() % ((uint32_t)tools::getWindowWidth() - 200) + 100.f;
	float randY = rand() % ((uint32_t)tools::getWindowHeight() - 400) + 100.f;
	Target target(res_manager.getTexture(GameResourceManager::TypeTexture::TARGET), type, sf::Vector2f(random_forward_vector_x, random_forward_vector_y), sf::Vector2f(randX, randY));
	target_list.push_back(target);
}