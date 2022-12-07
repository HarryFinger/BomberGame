#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

#include "Manager.h"
#include "Tools.h"


#ifdef GAME_DEBUG
int main()
#endif

#ifdef RELEASE
int WinMain()
#endif
{
    sf::RenderWindow window(sf::VideoMode(tools::getWindowWidth(), tools::getWindowHeight()), "BoomberGame", sf::Style::Titlebar | sf::Style::Close);
    window.setMouseCursorVisible(0);
    Manager manager;

    sf::Clock main_clock;
    float prev_time = main_clock.getElapsedTime().asSeconds();
    float time_accumulator = tools::getFPS();

    sf::Cursor cursor;

    while (window.isOpen())
    {
        //loop time calculation
        float current_time = main_clock.getElapsedTime().asSeconds();
        float loop_time = current_time - prev_time;
        time_accumulator += loop_time;

        prev_time = current_time;

        while (time_accumulator >= tools::getFPS())
        {
            //event state
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                manager.processInput(event);
            }

            //update state
            manager.update(tools::getFPS());

            //render state
            window.clear();
            manager.render(window);

            window.display();
            time_accumulator -= tools::getFPS();
        }
    }

    return 0;
}