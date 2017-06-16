/*
Downs, Josh
Summer - 2017
*/

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>
#include <iostream>

using namespace std;

const int TTT_SIZE = 3;

// @descrip - Executes the game of TicTacToe
void ticTacToe();

/*
@descrip - Checks to see if the game has been won
@param const char board[][] - current board in play
@param int col - col selected by the user (also denoted by column)
@param int row - row selected by the user (also dentoed by the row)
Note:  Remember the row/col axis starts with [0][0] in the top left corner
*/
bool checkWin(const char board[TTT_SIZE][TTT_SIZE], int col, int row);

/* 
@descrip - Displays the current board to the user
@param const char board[][] - current board in play
*/
void printBoard(const char board[TTT_SIZE][TTT_SIZE]);

/*
@descrip - Resets the board to the beginning state
@param char board[][] - current board in play
*/
void boardReset(char board[TTT_SIZE][TTT_SIZE]);

/*
@descrip - Verifies the space is available and inputs the correct players selection
@param char board[][] - current board in play
@param int col - column the player wishes to place their move
@param int row - row the player wishes to place their move
@param int playerTurn - the current players turn
@return - true for valid and false for an invalid selection
*/
bool validEntry(char board[TTT_SIZE][TTT_SIZE], int row, int col, int playerTurn);

/*
@descrip - Checks to see if there are any moves available, if no moves are available
		and no winner has been chosen it will return true
@param const char board[][] - current board in play
@return - false if there is a move open, true otherwise
*/
bool draw(const char board[TTT_SIZE][TTT_SIZE]);

#endif