#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include "Globals.h"

class EvilSq
{
	private:
		//Texture and Sprite
		sf::Texture enemyTextureUp;
		sf::Texture enemyTextureDown;
		sf::Texture enemyTextureLeft;
		sf::Texture enemyTextureRight;

		sf::Sprite enemySprite;

		int xPos = 0;
		int yPos = 0;

		int maxXpos = 0;
		int maxYpos = 0;

		int row = 0;
		int col = 0;

		int direction = 0;

		int timer = 0;

		bool wallSquareLeft = false;
		bool wallSquareRight = false;
		bool wallSquareUp = false;
		bool wallSquareDown = false;

	public:
		//Default Constructor
		EvilSq();

		//SetUp Textures and Sprites
		void setup();
		void loadTextures();
		void setSprite();
		void setPositionInArray(double t_xPos, double t_yPos);

		int getRow();
		int getCol();

		sf::Sprite getSprite();

		//Update
		void update();

		void checkForWallLeft(bool t_isAWall);
		void checkForWallRight(bool t_isAWall);
		void checkForWallUp(bool t_isAWall);
		void checkForWallDown(bool t_isAWall);


};
