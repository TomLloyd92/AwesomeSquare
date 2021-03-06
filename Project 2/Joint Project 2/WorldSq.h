#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

class WorldSq
{
private:
	//Texture and Sprite
	sf::Texture squareTexture;
	sf::Texture wallTexture;
	sf::Sprite squareSprite;

	int xPos = 0;
	int yPos = 0;

	bool isWallSquare = false;

public:
	//Default Constructor
	WorldSq();

	//SetUp Textures and Sprites
	void setup();
	void loadTextures();
	void setSprite();
	void setPosition(double t_xPos, double t_yPos);
	sf::Sprite getSprite();

	void setIsWallSquare(bool t_IsWallSquare);
	bool getIsWallSquare();

	//Update
	void update();

};