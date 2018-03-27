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

		int xPos;
		int yPos;

		int maxXpos;
		int maxYpos;

		int row;
		int col;

		bool alive;

		int direction = 0;

		int timer = 0;

		bool wallSquareLeft = false;
		bool wallSquareRight = false;
		bool wallSquareUp = false;
		bool wallSquareDown = false;

	public:
		//Default Constructor
		EvilSq();
		void kill();

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

		bool getAlive();

		//Reset Square
		void resetSquare();


};
