#pragma once

#include <iostream>
#include "SFML\Graphics.hpp"
#include "Globals.h"

class PlayerBomb
{
private:
	sf::Texture bombTexture;
	sf::Sprite bombSprite;
	sf::Texture explosionTexture;
	sf::Sprite explosionSprite;

	int xPos;
	int yPos;

	int col;
	int row;

	bool bombExploded;
	bool bombAlive;

	void setBody();
	void setTexture();
	void setSprite();

public:
	//default constructor
	PlayerBomb();

	void setRow(int t_row);
	void setCol(int t_col);
	void setBombAlive();

	bool getBombAlive();

	void update();

	sf::Sprite getSprite();


};