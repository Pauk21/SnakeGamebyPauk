#include "SnakeGame.h"


SnakeGame::SnakeGame()
{
	srand(time(0));
	isStarted = false;
	resetGame();
}

SnakeGame::~SnakeGame()
{
	delete[] gameGrid;
	std::cout << "Thanks for playing! <3";
}

void SnakeGame::update(sf::RenderWindow& window)
{
	for (size_t i = 0; i < 40; i++)	{
		for (size_t j = 0; j < 40; j++) {
			if (*(gameGrid + i * width + j) == 1) {
			snakePixel.setPosition(j * pixelSize, i * pixelSize);
			window.draw(snakePixel);
			}
			else if (*(gameGrid + i * width + j) == 2) {
				apple.setPosition(j * pixelSize, i * pixelSize);
				window.draw(apple);
			}
		}
	}

	logic();
}



void SnakeGame::logic()
{
	appleAte = false;
	if (checkAteApple()) {
		snakeLength++;
		appleAte = true;
		spawnApple();
	}
	moveSnake();
}

void SnakeGame::moveSnake()
{
	currX += moveX;
	currY += moveY;

	if (isDead())
		resetGame();
	else {
		snake.push(currY * width + currX);
		*(gameGrid + currY * width + currX) = 1;

		if (!appleAte) {
			*(gameGrid + snake.front()) = 0;
			snake.pop();
		}
	}	
}

bool SnakeGame::checkAteApple()
{
	if (currX == appleX && currY == appleY)
		return true;

	return false;
}

bool SnakeGame::isDead()
{
	return (*(gameGrid + currY * width + currX) == 1) || currX < 0 || currX >= width || currY < 0 || currY >= height;
}

void SnakeGame::resetGame()
{
	while (!snake.empty()) {
		snake.pop();
	}

	snakeLength = 2;
	moveX = 1;
	moveY = 0;
	currX = 20;
	currY = 20;
	appleAte = false;
	snakePixel = getSnakePixel();
	apple = getApple();
	spawnSnake();
	spawnApple();
}

void SnakeGame::changeDir(int X, int Y)
{
	oldMoveX = moveX;
	oldMoveY = moveY;
	moveX = X;
	moveY = Y;
}

sf::RectangleShape SnakeGame::getSnakePixel()
{
	sf::RectangleShape pixel(sf::Vector2f(pixelSize - 2, pixelSize - 2));
	pixel.setFillColor(sf::Color::Green);
	return pixel;
}

sf::RectangleShape SnakeGame::getApple()
{
	sf::RectangleShape pixel(sf::Vector2f(pixelSize - 2, pixelSize - 2));
	pixel.setFillColor(sf::Color::Red);
	return pixel;
}


void SnakeGame::spawnSnake()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			*(gameGrid + i * width + j) = 0;
		}
	}


	snake.push(20 * width + 20);
	*(gameGrid + snake.front()) = 0;
}

void SnakeGame::spawnApple()
{
	appleX = rand() % 40;
	appleY = rand() % 40;

	*(gameGrid + appleY * width + appleX) = 2;
}

