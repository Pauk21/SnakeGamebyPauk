#include <SFML/Graphics.hpp>
#include "SnakeGame.h"

int main()
{
	SnakeGame snake;

	sf::Clock frameClock;

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(800, 800), "Snake Game by Pauk", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Up)
					if (snake.moveY == 0)
						snake.changeDir(0, -1);
				if (event.key.code == sf::Keyboard::Down) 
					if (snake.moveY == 0)
						snake.changeDir(0, 1);
				if (event.key.code == sf::Keyboard::Left)
					if (snake.moveX == 0)
						snake.changeDir(-1, 0);	
				if (event.key.code == sf::Keyboard::Right)
					if (snake.moveX == 0)
						snake.changeDir(1, 0);
			}
		}
		sf::Time elapsed = frameClock.getElapsedTime();
		if (elapsed.asMilliseconds() >= 150) {
			window.clear();
			snake.update(window);
			window.display();
			frameClock.restart();
		}
	}

	return 0;
}