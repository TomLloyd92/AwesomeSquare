// Name: Tom Lloyd
// Login: C00231308
// Date: 02/03/2018
// Approximate time taken: 
//---------------------------------------------------------------------------
// Project description Template
// ---------------------------------------------------------------------------
// Known Bugs:
// List your bugs here

//////////////////////////////////////////////////////////// 
// Headers for SFML projects
// include correct library file for release and debug versions
// include iostream for console window output
// include 
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "Game.h"   // include Game header file

int main()
{
	Game aGame;
	aGame.LoadContent();
	aGame.run();

	return 0;
}

Game::Game() : window(sf::VideoMode(384, 384), "Project 2")
// Default constructor
{
}


void Game::LoadContent()
{
	//Load Font
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}

	//Set up the message string for Score
	m_messageScore.setFont(m_font); 
	m_messageScore.setCharacterSize(24); 
	m_messageScore.setFillColor(sf::Color::Blue); 
	m_messageScore.setPosition(5, 5); 
	m_messageScore.setString("Score:" + std::to_string(score));

	//Message to Replay the Game
	m_messageReplay.setFont(m_font);
	m_messageReplay.setCharacterSize(30);
	m_messageReplay.setFillColor(sf::Color::White);
	m_messageReplay.setPosition(90, 40);
	m_messageReplay.setString("		  GAME OVER! \n Press 'R' to Replay \n			     OR \n   'C' For controls");

	//Message for the Controls of the Game
	m_messageControls.setFont(m_font);
	m_messageControls.setCharacterSize(24);
	m_messageControls.setFillColor(sf::Color::Yellow);
	m_messageControls.setPosition(60, 230);
	m_messageControls.setString("      Use the Arrow Keys To move \nUse the Space Bar to kick a block \n			Use 'B' to drop a bomb");
}


void Game::run()
{
	srand(time(nullptr)); // set the seed once
	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;

	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			update();
			draw();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop
}

void Game::update()
{

		if (gameSetUp == false)
		{
			setUpMaze();
		}
		//Setting Up Maze
		for (int row = 0; row < MAX_SPACES; row++)
		{
			for (int col = 0; col < MAX_SPACES; col++)
			{
				{
					maze[row][col].update();	//Update the Square at that point
					maze[row][col].setPosition(col, row);	//Set the position of each square
				}
			}
		}//END nested loop for maze Update and Set Positions

		//Moving the Walls
		if (player.getMoveWallLeft() == true)
		{
			maze[player.getRow()][player.getCol() - 2].setIsWallSquare(true);
			maze[player.getRow()][player.getCol() - 1].setIsWallSquare(false);
			player.resetAllWallMove();
		}

		if (player.getMoveWallRight() == true)
		{
			maze[player.getRow()][player.getCol() + 2].setIsWallSquare(true);
			maze[player.getRow()][player.getCol() + 1].setIsWallSquare(false);
			player.resetAllWallMove();
		}

		if (player.getMoveWallUp() == true)
		{
			maze[player.getRow() - 2][player.getCol()].setIsWallSquare(true);
			maze[player.getRow() - 1][player.getCol()].setIsWallSquare(false);
			player.resetAllWallMove();
		}

		if (player.getMoveWallDown() == true)
		{
			maze[player.getRow() + 2][player.getCol()].setIsWallSquare(true);
			maze[player.getRow() + 1][player.getCol()].setIsWallSquare(false);
			player.resetAllWallMove();
		}

		//Player update
		if (player.getAlive() == true)
		{
			player.update();	//Update the Player
			
			m_messageScore.setString("Score:" + std::to_string(score)); //Set Score
			m_messageScore.setPosition(5, 5);

			//Checking surrounding squares
			player.checkForWallLeft(maze[player.getRow()][player.getCol() - 1].getIsWallSquare());	//Checking for walls LEFT
			player.checkForWallRight(maze[player.getRow()][player.getCol() + 1].getIsWallSquare());	//Checking for walls RIGHT
			player.checkForWallUp(maze[player.getRow() - 1][player.getCol()].getIsWallSquare());	//checlomg for walls UP
			player.checkForWallDown(maze[player.getRow() + 1][player.getCol()].getIsWallSquare());	//checking for walls DOWN

			//Enemy Update
			for (int i = 0; i < MAX_NO_ENEMYS; i++)
			{
				{
					enemys[i].checkForWallLeft(maze[enemys[i].getRow()][enemys[i].getCol() - 1].getIsWallSquare());		//Checking for Walls Left
					enemys[i].checkForWallRight(maze[enemys[i].getRow()][enemys[i].getCol() + 1].getIsWallSquare());	//Checking for Walls Right
					enemys[i].checkForWallUp(maze[enemys[i].getRow() - 1][enemys[i].getCol()].getIsWallSquare());		//Checking for Walls Up
					enemys[i].checkForWallDown(maze[enemys[i].getRow() + 1][enemys[i].getCol()].getIsWallSquare());		//Checking for Walls Down

					if (enemys[i].getAlive() == true)
					{
						enemys[i].update();	//Update all the enemys
					}
				}
			}

			//Collision Player and Enemys
			for (int index = 0; index < MAX_NO_ENEMYS; index++)
			{
				if (enemys[index].getAlive() == true)
				{
					if (enemys[index].getRow() == player.getRow() && enemys[index].getCol() == player.getCol())
					{
						player.isAlive(false);
					}
				}
			}

			for (int i = 0; i < MAX_NO_ENEMYS; i++)
			{
				int row = enemys[i].getRow();
				int col = enemys[i].getCol();

				if (enemys[i].getAlive() == true)
				{
					if (maze[row][col].getIsWallSquare() == true)
					{
						enemys[i].kill();
						score += 10;
						std::cout << std::to_string(score) << std::endl;
					}
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			{
				bomb.setBombAlive();
			}
		}
		else if (player.getAlive() == false)
		{
			m_messageScore.setPosition(120, 250);
			m_messageScore.setCharacterSize(50);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				player.isAlive(true);
				player.resetPlayer();

				m_messageScore.setCharacterSize(24);
				
				for (int i = 0; i < MAX_NO_ENEMYS; i++)
				{
					enemys[i].resetSquare();
				}

				for (int row = 0; row < MAX_SPACES; row++)	//Clear all squares to alow the level to be rebuilt
				{
					for (int col = 0; col < MAX_SPACES; col++)
					{
						maze[row][col].setIsWallSquare(false);
					}
				}

				gameSetUp = false;	//Will now rebuild the level
				controlScreenOn = false;

				score = 0;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
			{
				controlScreenOn = true;
			}

		}
}

void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	window.clear();

	if (player.getAlive() == true)
	{

		//Nested for loop of the maze
		for (int row = 0; row < MAX_SPACES; row++)	//Go Through Every Row
		{
			for (int col = 0; col < MAX_SPACES; col++)	//Go Through Every Col
			{
				window.draw(maze[row][col].getSprite());	//Draw The square at that point
			}
		}//END nested loop for maze Drawing

		//Draw Enemy
		for (int i = 0; i < MAX_NO_ENEMYS; i++)
		{
			if (enemys[i].getAlive() == true)
			{
				window.draw(enemys[i].getSprite());
			}
		}

		//Draw Player
		window.draw(player.getSprite());
	}

	if (player.getAlive() == false)
	{
		window.draw(m_messageReplay);
	}

	//Display Score Text
	if (controlScreenOn == false)
	{
		window.draw(m_messageScore);
	}

	if (controlScreenOn == true)
	{
		window.draw(m_messageControls);
	}

	window.display();
}

void Game::setUpMaze()
{
	//Set up outside walls
	for (int row = 0, col = 0; col < MAX_SPACES; col++)	//Set up Top Wall
	{
		maze[row][col].setIsWallSquare(true);
	}
	for (int row = 0, col = MAX_SPACES - 1; row < MAX_SPACES; row++)
	{
		maze[row][col].setIsWallSquare(true);
	}
	for (int row = MAX_SPACES - 1, col = 0; col < MAX_SPACES; col++)
	{
		maze[row][col].setIsWallSquare(true);
	}
	for (int row = 0, col = 0; row < MAX_SPACES; row++)
	{
		maze[row][col].setIsWallSquare(true);
	}//End Outside Walls

	 //Internal Maze
	for (int row = 3, col = 3; row < 9; row++)
	{
		maze[row][col].setIsWallSquare(true);
	}
	for (int row = 3, col = 6; row < 9; row++)
	{
		maze[row][col].setIsWallSquare(true);
	}
	for (int row = 3, col = 9; row < 9; row++)
	{
		maze[row][col].setIsWallSquare(true);
	}//end Internal Maze
	gameSetUp = true;
}


void Game::drawMaze()
{

}