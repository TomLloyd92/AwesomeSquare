// AwesomeSq function definitions here

#include "AwesomeSq.h"

AwesomeSq::AwesomeSq()
{
	setup();

	xPos = 32;
	yPos = 32;
}

void AwesomeSq::setup()
{
	loadTextures();
	setSprite();
}

void AwesomeSq::loadTextures()
{
	//Up
	if (!playerTextureUp.loadFromFile("ASSETS/Sprites/walkUp1.png"))
	{
		std::cout << "Load Failed: Player Up!" << std::endl;
	}
	//Down
	if (!playerTextureDown.loadFromFile("ASSETS/Sprites/walkDown1.png"))
	{
		std::cout << "Load Failed: Player Down!" << std::endl;
	}
	//Right
	if (!playerTextureRight.loadFromFile("ASSETS/Sprites/walkRight1.png"))
	{
		std::cout << "Load Failed: Player Right!" << std::endl;
	}
	//Left
	if (!playerTextureLeft.loadFromFile("ASSETS/Sprites/walkLeft1.png"))
	{
		std::cout << "Load Failed: Player Left!" << std::endl;
	}
}

void AwesomeSq::setSprite()
{
	playerSprite.setTexture(playerTextureDown);
}

void AwesomeSq::setPositionInArray(double t_col, double t_row)
{
	xPos = t_col * 32;
	yPos = t_row * 32;
}

int AwesomeSq::getRow()
{
	return row;
}

int AwesomeSq::getCol()
{
	return col;
}

sf::Sprite AwesomeSq::getSprite()
{
	return sf::Sprite(playerSprite);
}

void AwesomeSq::checkForWallLeft(bool t_isAWall)
{
	wallSquareLeft = t_isAWall; 
}

void AwesomeSq::checkForWallRight(bool t_isAWall)
{
	wallSquareRight = t_isAWall;
}

void AwesomeSq::checkForWallUp(bool t_isAWall)
{
	wallSquareUp = t_isAWall;
}

void AwesomeSq::checkForWallDown(bool t_isAWall)
{
	wallSquareDown = t_isAWall;
}

void AwesomeSq::isAlive(bool t_isAlive)
{
	alive = t_isAlive;
}

bool AwesomeSq::getAlive()
{
	return alive;
}

bool AwesomeSq::getMoveWallLeft()
{
	return moveWallLeft;
}

bool AwesomeSq::getMoveWallRight()
{
	return moveWallRight;
}

bool AwesomeSq::getMoveWallUp()
{
	return moveWallUp;
}

bool AwesomeSq::getMoveWallDown()
{
	return moveWallDown;
}

void AwesomeSq::resetAllWallMove()
{
	moveWallLeft = false;
	moveWallRight = false;
	moveWallUp = false;
	moveWallDown = false;
}

void AwesomeSq::resetPlayer()
{
	xPos = 32;
	yPos = 32;

	row = 1;
	col = 1;

}

void AwesomeSq::update()
{
	if (timer > 0)
	{
		timer--;
	}

	if (timer == 0)
	{
		if (xPos == maxXPos && yPos == maxYPos)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				timer = TIMER_MAX;
				playerSprite.setTexture(playerTextureLeft);
				if (col > 0)
				{
					direction = WEST;


					if (wallSquareLeft == false)	//Check for Wall Block
					{
						col--;	//Move Player
					}
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				timer = TIMER_MAX;
				playerSprite.setTexture(playerTextureRight);
				if (col < MAX_SPACES - 1)
				{
					direction = EAST;

					if (wallSquareRight == false)	//Check for Wall Block
					{
						col++;	//Move Player
					}

				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				timer = TIMER_MAX;
				playerSprite.setTexture(playerTextureUp);
				if (row > 0)
				{
					direction = NORTH;

					if (wallSquareUp == false)	//Check for Wall Block
					{
						row--;	//Move Player
					}
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				timer = TIMER_MAX;
				playerSprite.setTexture(playerTextureDown);
				if (row < MAX_SPACES - 1)
				{
					direction = SOUTH;

					if (wallSquareDown == false)
					{
						row++;
					}
				}
			}
		}
	
		//Kick: if there is a wall in the facing direction and space is clicked the wall moves in direction facing player by 1 
		//as long as row or col isnt = to 0
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (direction == WEST && wallSquareLeft == true)
			{
				moveWallLeft = true;
			}
			if (direction == NORTH && wallSquareUp == true)
			{
				moveWallUp = true;
			}
			if (direction == EAST && wallSquareRight == true)
			{
				moveWallRight = true;
			}
			if (direction == SOUTH && wallSquareDown == true)
			{
				moveWallDown = true;
			}
		}
	}

	//Max Position of the x and y axis
	maxXPos = col * 32.0;
	maxYPos = row * 32.0;

	//Move the player with fluid Motion
	if (xPos < maxXPos)
	{
		xPos++;	//Right
	}
	if (yPos < maxYPos)
	{
		yPos++;	//Down
	}
	if (xPos > maxXPos)
	{
		xPos--;	//Left
	}
	if(yPos > maxYPos)
	{
		yPos--;	//Right
	}



	playerSprite.setPosition(xPos, yPos);

}
