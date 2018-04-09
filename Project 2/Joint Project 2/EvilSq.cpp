// EvilSq function definitions here

#include "EvilSq.h"

EvilSq::EvilSq()
{
	//Setup Sprites/textures
	setup();


	row = rand() % 12;
	col = rand() % 12;

	if (row == 0 || row == 11)
	{
		row = 5;
	}

	if (col == 0 ||col == 11)
	{
		col = 5;
	}
	maxXpos = col * 32.0;
	maxYpos = row * 32.0;

	xPos = maxXpos;
	yPos = maxYpos;

	direction = rand() % 4 + 1;
	alive = true;
}

void EvilSq::kill()
{
	alive = false;
}

void EvilSq::setup()
{
	loadTextures();
	setSprite();
}

void EvilSq::loadTextures()
{
	//Up
	if (!enemyTextureUp.loadFromFile("ASSETS/SPRITES/beeFront.png"))
	{
		std::cout << "Load Failed: Player Up!" << std::endl;
	}
	
	if (!enemyTextureDown.loadFromFile("ASSETS/Sprites/BeeBack.png"))
	{
		std::cout << "Load Failed: Player Down!" << std::endl;
	}
	
	if (!enemyTextureRight.loadFromFile("ASSETS/Sprites/BeeRight.png"))
	{
		std::cout << "Load Failed: Player Right!" << std::endl;
	}
	//Left
	if (!enemyTextureLeft.loadFromFile("ASSETS/Sprites/BeeLeft.png"))
	{
		std::cout << "Load Failed: Player Left!" << std::endl;
	}
}

void EvilSq::setSprite()
{
	enemySprite.setTexture(enemyTextureUp);
}

void EvilSq::setPositionInArray(double t_xPos, double t_yPos)
{
	xPos = t_xPos * 32;
	yPos = t_yPos * 32;
	enemySprite.setPosition(xPos, yPos);
}

int EvilSq::getRow()
{
	return row;
}

int EvilSq::getCol()
{
	return col;
}

sf::Sprite EvilSq::getSprite()
{
	return sf::Sprite(enemySprite);
}

void EvilSq::update()
{
	//Set Sprites
	if (direction == NORTH)
	{
		enemySprite.setTexture(enemyTextureUp);
	}
	else if (direction == SOUTH)
	{
		enemySprite.setTexture(enemyTextureDown);
	}
	else if (direction == EAST)
	{
		enemySprite.setTexture(enemyTextureRight);
	}
	else if (direction == WEST)
	{
		enemySprite.setTexture(enemyTextureLeft);
	}

	//Timer
	if (timer > 0)
	{
		timer--;
	}

	if (timer == 0)
	{
		if (maxXpos == xPos && maxYpos == yPos)
		{
			if (direction == NORTH && wallSquareUp == false)
			{
				row--;
				timer = TIMER_MAX;
			}
			else if (direction == SOUTH && wallSquareDown == false)
			{
				row++;
				timer = TIMER_MAX;
			}
			else if (direction == EAST && wallSquareRight == false)
			{
				col++;
				timer = TIMER_MAX;
			}
			else if (direction == WEST && wallSquareLeft == false)
			{
				col--;
				timer = TIMER_MAX;
			}
			else
			{
				direction = rand() % 4 + 1;
				timer = TIMER_MAX;
			}
		}
	}

	//Max Position of the x and y axis
	maxXpos = col * 32.0;
	maxYpos = row * 32.0;

	//Move the player with fluid Motion
	if (xPos < maxXpos)
	{
		xPos++;	//Right
	}
	if (yPos < maxYpos)
	{
		yPos++;	//Down
	}
	if (xPos > maxXpos)
	{
		xPos--;	//Left
	}
	if (yPos > maxYpos)
	{
		yPos--;	//Right
	}

	enemySprite.setPosition(xPos,yPos);
}

void EvilSq::checkForWallLeft(bool t_isAWall)
{
	wallSquareLeft = t_isAWall;
}

void EvilSq::checkForWallRight(bool t_isAWall)
{
	wallSquareRight = t_isAWall;
}

void EvilSq::checkForWallUp(bool t_isAWall)
{
	wallSquareUp = t_isAWall;
}

void EvilSq::checkForWallDown(bool t_isAWall)
{
	wallSquareDown = t_isAWall;
}

bool EvilSq::getAlive()
{
	return alive;
}

void EvilSq::resetSquare()
{
	alive = true;

	row = rand() % 12;
	col = rand() % 12;

	if (row == 0 || row == 11)
	{
		row = 5;
	}

	if (col == 0 || col == 11)
	{
		col = 5;
	}
	maxXpos = col * 32.0;
	maxYpos = row * 32.0;

	xPos = maxXpos;
	yPos = maxYpos;

	direction = rand() % 4 + 1;
}
