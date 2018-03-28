#pragma once

#include <iostream>
#include "SFML\Graphics.hpp"
#include "Globals.h"

class Explosion
{
private:
	sf::Texture explosionTexture;
	sf::Sprite explosionSprite;

	int xPos;
	int yPos;

	int col;
	int row;

	bool explosionAlive;

	void setBody();
	void setTexture();
	void setSprite();


public:
	Explosion();

	//Set up
	void setRow(int t_row);
	void setCol(int t_col);
	void setExplosionAlive(bool t_bombAlive);

	//Get
	int getRow();
	int getCol();

	bool getExplosionAlive();

	void update();

	sf::Sprite getSprite();



};