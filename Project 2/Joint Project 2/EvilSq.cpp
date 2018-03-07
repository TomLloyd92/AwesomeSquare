// EvilSq function definitions here

#include "EvilSq.h"

EvilSq::EvilSq()
{
	setup();

	int randX = rand() % 12;
	int randY = rand() % 12;

	setPositionInArray(randX, randY);
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

	/*
	//Down
	if (!enemyTextureDown.loadFromFile("ASSETS/Sprites/enemySquare.png"))
	{
		std::cout << "Load Failed: Player Down!" << std::endl;
	}
	//Right
	if (!enemyTextureRight.loadFromFile("ASSETS/Sprites/enemySqaure.png"))
	{
		std::cout << "Load Failed: Player Right!" << std::endl;
	}
	//Left
	if (!enemyTextureLeft.loadFromFile("ASSETS/Sprites/enemySquare.png"))
	{
		std::cout << "Load Failed: Player Left!" << std::endl;
	}
	*/

}

void EvilSq::setSprite()
{
	enemySprite.setTexture(enemyTextureUp);
}

void EvilSq::setPositionInArray(double t_xPos, double t_yPos)
{
	xPos = t_xPos * 32;
	yPos = t_yPos * 32;
}

sf::Sprite EvilSq::getSprite()
{
	return sf::Sprite(enemySprite);
}

void EvilSq::update()
{
	enemySprite.setPosition(xPos, yPos);
}
