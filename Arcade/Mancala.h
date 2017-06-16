/*
Downs, Josh
Summer - 2017
*/

#ifndef MANCALA_H
#define MANCALA_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// Size of the board, 12 slots + 2 captures
const int MANCALA_SIZE = 14;

// @descrip - executes the game of mancala
void mancala();

/*
@descrip - Validates selected move
@param const int board[] - current board in play
@param int playerTurn - current player whose turn it is
@param int selection - square the current player wishes to move
@return - true if the move is valid, false otherwise
*/
bool validEntry(const int *board, int playerTurn, int selection);

/*
@descrip - Prints the current board
@param const int board[] - current board in play

The array corresponds to the board being laid out like this:

	Player 2s side

   13 12 11 10  9  8
 0                   7
    1  2  3  4  5  6

    Player 1s side

Capture points are to the RIGHT of each player
	0 - Player 2 Capture
	7 - Player 1 Capture

*/
void printBoard(const int *board);

/*
@descrip - Resets the board to the starting state
@param int board[] - current board in play
*/
void resetBoard(int *board);

// Prints the rules for mancala
void printRules();

/*
@descrip - Checks to see if you capture the opposite side
@param int board[] - current board in play
@param int playerTurn - current players turn
@param int move - the position of the last marble
*/
void captureOpposite(int *board, int playerTurn, int move);

/*
@descrip - Checks to see if the game is over
@param int board[] - current board in play
@return - true if a side is empty, false otherwise
*/
bool winCondition(int *board);

#endif