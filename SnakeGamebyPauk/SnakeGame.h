#pragma once
#include <SFML/Graphics.hpp>
#include <queue>

#define pixelSize 20
#define height 40
#define width 40

class SnakeGame
{
private:
	sf::RectangleShape snakePixel;
	sf::RectangleShape apple;

	int* gameGrid = new int[height * width];
	bool isStarted;
	int snakeLength;

	int currX;
	int currY;

	int appleX;
	int appleY;

	bool appleAte;

	std::queue<int> snake;

	sf::RectangleShape getSnakePixel();
	sf::RectangleShape getApple();
	void logic();
	void moveSnake();
	void spawnSnake();
	void spawnApple();
	bool checkAteApple();
	bool isDead();
	void resetGame();

public:
	SnakeGame();
	~SnakeGame();
	void update(sf::RenderWindow& window);

	int moveX;
	int moveY;
	int oldMoveX;
	int oldMoveY;
	void changeDir(int X, int Y);
};

