#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>


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

	public:
		//Default Constructor
		EvilSq();

		//SetUp Textures and Sprites
		void setup();
		void loadTextures();
		void setSprite();
		void setPositionInArray(double t_xPos, double t_yPos);
		sf::Sprite getSprite();

		//Update
		void update();
};
