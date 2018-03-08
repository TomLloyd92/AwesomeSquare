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

Game::Game() : window(sf::VideoMode(400, 400), "Project 2")
// Default constructor
{
}


void Game::LoadContent()
// load the font file & set up message
{
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}
	
	// set up the message string 
	m_message.setFont(m_font);  // set the font for the text
	m_message.setCharacterSize(24); // set the text size
	m_message.setFillColor(sf::Color::White); // set the text colour
	m_message.setPosition(10, 10);  // its position on the screen
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
// This function takes the keyboard input and updates the game world
{
	//Setting Up Maze
	//Nested for loop of the maze Updates and Set Positions
	for (int row = 0; row < MAX_SPACES; row++)	//Go Through Every Row
	{
		for (int col = 0; col < MAX_SPACES; col++)	//Go Through Every Col
		{
			{
				maze[row][col].update();	//Update the Square at that point
				maze[row][col].setPosition(col, row);	//Set the position of each square
			}		
		}
	}//END nested loop for maze Update and Set Positions

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


	//Player update
	if (player.getAlive() == true)
	{
		player.update();	//Update the Player
		//Checking surrounding squares
		player.checkForWallLeft(maze[player.getRow()][player.getCol() - 1].getIsWallSquare());	//Checking for walls LEFT
		player.checkForWallRight(maze[player.getRow()][player.getCol() + 1].getIsWallSquare());	//Checking for walls RIGHT
		player.checkForWallUp(maze[player.getRow() - 1][player.getCol()].getIsWallSquare());	//checlomg for walls UP
		player.checkForWallDown(maze[player.getRow() + 1][player.getCol()].getIsWallSquare());	//checking for walls DOWN

		//Enemy Update
		for (int i = 0; i < MAX_NO_ENEMYS; i++)
		{
			enemys[i].checkForWallLeft(maze[enemys[i].getRow()][enemys[i].getCol() - 1].getIsWallSquare());		//Checking for Walls Left
			enemys[i].checkForWallRight(maze[enemys[i].getRow()][enemys[i].getCol() + 1].getIsWallSquare());	//Checking for Walls Right
			enemys[i].checkForWallUp(maze[enemys[i].getRow() - 1][enemys[i].getCol()].getIsWallSquare());		//Checking for Walls Up
			enemys[i].checkForWallDown(maze[enemys[i].getRow() + 1][enemys[i].getCol()].getIsWallSquare());		//Checking for Walls Down
			enemys[i].update();	//Update all the enemys
		}

		//Collision
		for (int index = 0; index < MAX_NO_ENEMYS; index++)
		{
			if (enemys[index].getRow() == player.getRow() && enemys[index].getCol() == player.getCol())
			{
				player.isAlive(false);
			}
		}
	}
}

void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	window.clear();

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
		window.draw(enemys[i].getSprite());
	}

	//Draw Player
	window.draw(player.getSprite());

	window.display();
}

void Game::setUpMaze()
{

}


void Game::drawMaze()
{

}