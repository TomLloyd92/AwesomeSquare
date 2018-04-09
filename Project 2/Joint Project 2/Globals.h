#pragma once

//Squares
const int BLANK = 0;
const int WORLD_SQUARE = 1;

//Maximum Number Of Spaces In The Game
const int MAX_SPACES = 12;

//Maximum Number Of Enemys
const int MAX_NO_ENEMYS = 3;

//Maximum Explosions
const int MAX_EXPLOSION = 5;

//Direction
const int NORTH = 1;
const int EAST = 2;
const int SOUTH = 3;
const int WEST = 4;

//Timer
const int TIMER_MAX = 10;

//GameStates
enum class GameStates { MAIN_MENU, PLAYING, GAME_OVER, CONTROLS};