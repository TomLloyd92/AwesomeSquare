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


class Game
{
	// private data members
	// put your game objects here eg AwesomeSq object and 1D array of EvilSq objects etc.

	sf::RenderWindow window;

public:
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen

public:	  // declaration of member functions	
	Game();  // default constructor
	void	LoadContent();
	void	run();
	void	update();
	void	draw();
	void	setUpMaze();
	void	drawMaze();

	bool gameSetUp = false;

	//Objects
	WorldSq maze[MAX_SPACES][MAX_SPACES];
	AwesomeSq player;
	EvilSq enemys[MAX_NO_ENEMYS];
};

