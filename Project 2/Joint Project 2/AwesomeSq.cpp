// AwesomeSq function definitions here

#include "AwesomeSq.h"

AwesomeSq::AwesomeSq()
{
	setup();
}

void AwesomeSq::setup()
{
	loadTextures();
	setSprite();
}

void AwesomeSq::loadTextures()
{
	//Up
	if (!playerTextureUp.loadFromFile("ASSETS/Sprites/playerUp.png"))
	{
		std::cout << "Load Failed: Player Up!" << std::endl;
	}
	//Down
	if (!playerTextureDown.loadFromFile("ASSETS/Sprites/playerDown.png"))
	{
		std::cout << "Load Failed: Player Down!" << std::endl;
	}
	//Right
	if (!playerTextureRight.loadFromFile("ASSETS/Sprites/playerRight.png"))
	{
		std::cout << "Load Failed: Player Right!" << std::endl;
	}
	//Left
	if (!playerTextureLeft.loadFromFile("ASSETS/Sprites/playerLeft.png"))
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

sf::Sprite AwesomeSq::getSprite()
{
	return sf::Sprite(playerSprite);
}

void AwesomeSq::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		playerSprite.setTexture(playerTextureLeft);
		if (col > 0)
		{
			col--;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		playerSprite.setTexture(playerTextureRight);
		if (col < MAX_SPACES - 1)
		{
			col++;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		playerSprite.setTexture(playerTextureUp);
		if (row > 0)
		{
			row--;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		playerSprite.setTexture(playerTextureDown);
		if (row < MAX_SPACES - 1)
		{
			row++;
		}
	}

	xPos = col * 32;
	yPos = row * 32;

	playerSprite.setPosition(xPos, yPos);

}
