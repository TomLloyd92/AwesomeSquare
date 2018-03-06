#pragma once

#include <iostream>
#include "SFML\Graphics.hpp"
#include "Globals.h"

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

	int row = 0;
	int col = 0;

public:
	//Default Constructor
	AwesomeSq();

	//SetUp Textures and Sprites
	void setup();
	void loadTextures();
	void setSprite();
	void setPositionInArray(double t_xPos, double t_yPos);
	sf::Sprite getSprite();

	//Update
	void update();
};