#pragma once

#include <iostream>
#include "SFML\Graphics.hpp"
#include "Globals.h"
#include "WorldSq.h"

class AwesomeSq
{
private:
	//Texture and Sprite
	sf::Texture playerTextureUp;
	sf::Texture playerTextureDown;
	sf::Texture playerTextureLeft;
	sf::Texture playerTextureRight;

	sf::Sprite playerSprite;

	int xPos = 0;
	int yPos = 0;

	int row = 1;
	int col = 1;

	int direction;

public:
	//Default Constructor
	AwesomeSq();

	//SetUp Textures and Sprites
	void setup();
	void loadTextures();
	void setSprite();
	void setPositionInArray(double t_xPos, double t_yPos);

	//void getTheMazeArray(WorldSq t_theArray[MAX_SPACES][MAX_SPACES]);

	sf::Sprite getSprite();

	//Update
	void update();
};