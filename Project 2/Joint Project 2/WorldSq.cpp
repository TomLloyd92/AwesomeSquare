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
	if (!squareTexture.loadFromFile("ASSETS/SPRITES/emptySquare.png"))	//Load png into square texture
	{
		std::cout << "Load Failed!" << std::endl;	//If failed to laod output to the console
	}
}

//Set up Sprite
void WorldSq::setSprite()
{
	squareSprite.setTexture(squareTexture);	//Set the sprite to the texture
}

//Constant update of square
void WorldSq::update()
{
	squareSprite.setPosition(xPos,yPos);
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
