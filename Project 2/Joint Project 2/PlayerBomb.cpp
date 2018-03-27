#include "PlayerBomb.h"

PlayerBomb::PlayerBomb()
{
	setBody();
}

void PlayerBomb::setBody()
{
	setTexture();
	setSprite();
}

void PlayerBomb::setTexture()
{
	if (!bombTexture.loadFromFile("ASSETS/Sprites/bomb.png"))
	{
		std::cout << "Bomb not loaded" << std::endl;
	}
}

void PlayerBomb::setSprite()
{
	bombSprite.setTexture(bombTexture);
}


void PlayerBomb::setRow(int t_row)
{
	row = t_row;
}

void PlayerBomb::setCol(int t_col)
{
	col = t_col;
}

void PlayerBomb::setBombAlive()
{
	bombAlive = true;
}

bool PlayerBomb::getBombAlive()
{
	return bombAlive;
}

sf::Sprite PlayerBomb::getSprite()
{
	return sf::Sprite(bombSprite);
}
