/*
Downs, Josh
Summer - 2017
*/

#ifndef MEMORYMATCH_H
#define MEMORYMATCH_H

#include <string>
#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

const int MEMORYMATCH_SIZE = 6;

// @descrip - Begins the game of Memory Match
void memoryMatch();

/*
@descrip - prints the current board
@param const char board[][] - current board in play
*/
void printBoard(const char board[][MEMORYMATCH_SIZE]);

/*
@descrip - resets board to its beginning state and
	populates the masterBoard with the solution
@param char board[][] - current board in play
@param char masterBoard[][] - current solution board
*/
void resetBoards(char board[][MEMORYMATCH_SIZE], 
	char masterBoard[][MEMORYMATCH_SIZE]);

/*
@descrip - makes sure an appropriate value was entered
@param char board[][] - current board in play
@param int col - column position of the selection
@param int row - row position of the selection
@return - true if valid, false otherwise
*/
bool validEntry(const char board[][MEMORYMATCH_SIZE], int col, int row);

/*
@descrip - checks to see if the two selections match
@param const char masterBoard[][] - current solution board
@param int col1 - col position of the first letter
@param int row1 - row position of the first letter
@param int col2 - col posision of the second letter
@param int row2 - row position of the second letter
@return - true if they match, false otherwise
*/
bool matchFound(const char masterBoard[][MEMORYMATCH_SIZE],
	int col1, int row1, int col2, int row2);

/*
@descrip - checks to see if all pairs have been found
@param const char board[][] - current board in play
@return - false if non empty selection is found, true otherwise
*/
bool gameOver(const char board[][MEMORYMATCH_SIZE]);

#endif