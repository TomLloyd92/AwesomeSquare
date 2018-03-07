#include "WorldSq.h"

//Default Constructor
WorldSq::WorldSq()
{
	setup();	//Set up Textures and Sprites
}

//Set up Texture and Sprites
void WorldSq::setup()
{
	loadTextures();
	setSprite();
}

//Loading textures
void WorldSq::loadTextures()
{
	if (!squareTexture.loadFromFile("ASSETS/SPRITES/emptyBlock.png"))	//Load png into square texture
	{
		std::cout << "Load Failed Empty Square!" << std::endl;	//If failed to laod output to the console
	}

	if (!wallTexture.loadFromFile("ASSETS/SPRITES/block.png"))
	{
		std::cout << "Load Failed Block" << std::endl;
	}
}

//Set up Sprite
void WorldSq::setSprite()
{
	if (isWallSquare == false)
	{
		squareSprite.setTexture(squareTexture);	//Set the sprite to be and empty block
	}
	else if (isWallSquare == true)
	{
		squareSprite.setTexture(wallTexture);	//Set the Sprite to be a wall
	}
}

//Constant update of square
void WorldSq::update()
{
	squareSprite.setPosition(xPos,yPos);

	setSprite();
}

//Set Position of Square
void WorldSq::setPosition(double t_xPos, double t_yPos)
{
	xPos = t_xPos * 32;
	yPos = t_yPos * 32;
}

sf::Sprite WorldSq::getSprite()
{
	return sf::Sprite(squareSprite);
}

bool WorldSq::setIsWallSquare(bool t_IsWallSquare)
{
	if (t_IsWallSquare == true)
	{
		isWallSquare = t_IsWallSquare;
	}
	else if (t_IsWallSquare == false)
	{
		isWallSquare = t_IsWallSquare;
	}
	return false;
}

bool WorldSq::getIsWallSquare()
{
	return isWallSquare;
}
