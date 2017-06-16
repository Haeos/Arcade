/*
Downs, Josh
Summer - 2017
*/

#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H

#include <string>
#include <iostream>

using namespace std;

const int ROW = 6, COL = 7;

// @descrip - Executes the game of ConnectFour
void connectFour();

/*
the check___ functions are used to check the various win conditions
available in connect four.

@param int col - the column selected by the user
@param int row - holds the row of the last move
@param char board[][] - the current board being used for the game

Only necessary to check the areas around the [row][col] for win condition

checkHorizontal - checks for horizontally
checkVertical - checks vertically
checkRightDiagonal - checks from the top left to bottom right
checkLeftDiagonal - checks from top right to bottom left
*/
bool checkHorizontal(int row, const char board[ROW][COL]);
bool checkVertical(int col, const char board[ROW][COL]);
bool checkRightDiagonal(int col, int row, const char board[ROW][COL]);
bool checkLeftDiagonal(int col, int row, const char board[ROW][COL]);

// @descrip - Displays the current board
void printBoard(const char board[ROW][COL]);

// Resets the board to the beginning state
void boardReset(char board[ROW][COL]);

/*
* Verifies the space is available and inputs the correct players selection
* @param board[][] current board being used
* @param x column the player wishes to place their move
* @param playerTurn the current players turn
* @return returns true for valid and false for an invalid selection
*/
bool validEntry(char board[ROW][COL], int col, int playerTurn);

// Ends the game if there are no moves left and endOfGame is still false
bool draw(const char board[ROW][COL]);

#endif
