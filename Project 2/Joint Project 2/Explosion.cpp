#include "Explosion.h"

Explosion::Explosion()
{
	setBody();

}
void Explosion::setBody()
{
	setTexture();
	setSprite();
}

void Explosion::setTexture()
{
	if (!explosionTexture.loadFromFile("ASSETS/Sprites/Explosion.png"))
	{
		std::cout << "Explosion not loaded" << std::endl;
	}
}

void Explosion::setSprite()
{
	explosionSprite.setTexture(explosionTexture);
}

void Explosion::setRow(int t_row)
{
	row = t_row;
}

void Explosion::setCol(int t_col)
{
	col = t_col;
}

void Explosion::setExplosionAlive(bool t_bombAlive)
{
	explosionAlive = t_bombAlive;
}

int Explosion::getRow()
{
	return row;
}

int Explosion::getCol()
{
	return col;
}

bool Explosion::getExplosionAlive()
{
	return explosionAlive;
}

void Explosion::update()
{
	explosionSprite.setPosition(col* 32, row* 32);
}

sf::Sprite Explosion::getSprite()
{
	return sf::Sprite(explosionSprite);
}



