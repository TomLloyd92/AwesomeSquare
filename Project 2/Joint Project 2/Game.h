// Game class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>
#include <ctime>   

//Include Class Headers
#include "AwesomeSq.h"
#include "EvilSq.h"   
#include "WorldSq.h"
#include "Globals.h"
#include "PlayerBomb.h"	
#include "Explosion.h"	


class Game
{
private:
	//Objects
	WorldSq maze[MAX_SPACES][MAX_SPACES];
	AwesomeSq player;
	EvilSq enemys[MAX_NO_ENEMYS];
	PlayerBomb bomb;
	Explosion explosionBlast[MAX_EXPLOSION];
	
	GameStates gameState = GameStates::PLAYING;
	bool controlScreenOn = false;

	//Text for Score
	sf::Font m_font;
	sf::Text m_messageScore;
	sf::Text m_messageReplay;
	sf::Text m_messageControls;

	//Levels and Setup
	bool gameSetUp = false;

	//Game Varibles
	int bombTimer = 0;
	int explosionTimer = 0;
	int score = 0;

	//Window
	sf::RenderWindow window;

public:
	Game();
	void	LoadContent();
	void	run();
	void	update();
	void	draw();
	void	setUpMaze();
	void	drawMaze();
	
};

