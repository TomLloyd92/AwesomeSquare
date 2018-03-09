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

	double xPos = 0;
	double yPos = 0;

	double maxXPos = 0;
	double maxYPos = 0;

	int row = 1;
	int col = 1;

	int timer = 0;

	int direction;

public:
	//Default Constructor
	AwesomeSq();

	//SetUp Textures and Sprites
	void setup();
	void loadTextures();
	void setSprite();
	void setPositionInArray(double t_xPos, double t_yPos);

	int getRow();
	int getCol();

	sf::Sprite getSprite();

	//Checking for walls
	void checkForWallLeft(bool t_isAWall);
	void checkForWallRight(bool t_isAWall);
	void checkForWallUp(bool t_isAWall);
	void checkForWallDown(bool t_isAWall);
	//wall Bools
	bool wallSquareLeft = false;
	bool wallSquareRight = false;
	bool wallSquareUp = false;
	bool wallSquareDown = false;

	//Checking for Player Alive
	bool alive = true;
	void isAlive(bool t_isAlive);
	bool getAlive();

	//Moving The Walls
	bool moveWallLeft = false;
	bool moveWallRight = false;
	bool moveWallUp = false;
	bool moveWallDown = false;

	bool getMoveWallLeft();
	//bool getMoveWallRight();
	//bool getMoveWallUp();
	//bool getMoveWallDown();

	void resetAllWallMove();

	//Update
	void update();
};