// Game class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

#include "AwesomeSq.h"   // include AwesomeSq header file
#include "EvilSq.h"   // include EvilSq header file
#include "WorldSq.h"	//Include World Square Header File
#include "Globals.h" //include global header file
#include "PlayerBomb.h"	//include the bomb header


class Game
{
	// private data members
	// put your game objects here eg AwesomeSq object and 1D array of EvilSq objects etc.

	sf::RenderWindow window;

public:	  // declaration of member functions	
	Game();  // default constructor
	void	LoadContent();
	void	run();
	void	update();
	void	draw();
	void	setUpMaze();
	void	drawMaze();


	bool gameSetUp = false;
	bool controlScreenOn = false;

	int score = 0;

	//Objects
	WorldSq maze[MAX_SPACES][MAX_SPACES];
	AwesomeSq player;
	EvilSq enemys[MAX_NO_ENEMYS];
	PlayerBomb bomb;

	GameStates gameState = GameStates::PLAYING;

	//Text for Score
	sf::Font m_font;  // font for writing text
	sf::Text m_messageScore;
	sf::Text m_messageReplay;
	sf::Text m_messageControls;
	
};

