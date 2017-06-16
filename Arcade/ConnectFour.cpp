/*
Downs, Josh
Summer - 2017
*/

#include "ConnectFour.h"

void connectFour()
{
	char board[ROW][COL];
	boardReset(board);

	cout << "//////////////////////////////////////////////////" << endl
		<< "//           Welcome to Connect Four!           //" << endl
		<< "//                                              //" << endl
		<< "//   The first player to connect four wins!     //" << endl
		<< "//            Player 1 will be \"x\"              //" << endl
		<< "//            Player 2 will be \"o\"              //" << endl
		<< "//////////////////////////////////////////////////" << endl
		<< endl
		<< "The starting board is:" << endl << endl;

	// Will keep track of the players turn through modding by 2 
	// and adding 1 so it alternates between the two players
	int playerTurn = 1;

	bool endOfGame = false, tie = false;

	while (!endOfGame && !tie)
	{
		printBoard(board);
		cout << endl;

		cout << "Player " << playerTurn << " select your column: ";
		int col;
		cin >> col;
		
		// decrementation accounts for 0 base
		if (validEntry(board, --col, playerTurn))
		{
			playerTurn = playerTurn % 2 + 1;

			// Figuring out the y position of the last move
			int row = ROW - 1;
			while (board[row][col] != '.' && row >= 0)
				--row;
			++row; // The loop above will always decrement it one too many times

			// Checking for win condition
			endOfGame = checkHorizontal(row, board) || checkVertical(col, board)
				|| checkLeftDiagonal(col, row, board) || checkRightDiagonal(col, row, board);
		} // end validEntry()
		else
			cout << endl << "Invalid entry detected, please try again"
				<< endl << endl;

		tie = draw(board);
	} // end endOfGame loop
	printBoard(board);

	playerTurn = playerTurn % 2 + 1;
	if (!tie)
		cout << endl << "Congratulations Player " << playerTurn
		<< " you are the winner!" << endl << endl;
	else
		cout << endl << "It's a tie!" << endl << endl;
} // end connectFour()

bool checkHorizontal(int row, const char board[ROW][COL])
{
	int counter = 0;
	for (int j = 1; j < COL; j++)
	{
		if (board[row][j - 1] == board[row][j] && board[row][j] != '.')
			counter++;
		else
			counter = 0;
		if (counter == 3)
			return true;
	}
	return false;
} // end checkHorizontal

bool checkVertical(int col, const char board[ROW][COL])
{
	int counter = 0;
	for (int j = 1; j < ROW; j++)
	{
		if (board[j - 1][col] == board[j][col] && board[j][col] != '.')
			counter++;
		else
			counter = 0;
		if (counter == 3)
			return true;
	}
	return false;
} // end checkVertical

bool checkRightDiagonal(int col, int row, const char board[ROW][COL])
{
	// Checking for diagonal victory
	// CheckRow and checkCol are -4 because they immediately get incremented/decremented inside the loop
	// this is done to make sure the commparisons stay within the confines of the array
	// Have to check 3 spaces on either side of the latest pieces position for win condition

	// Checking top right to bottom left
	int counter = 0;
	int checkRow = row - 4;
	int checkCol = col - 4;

	// Makes sure the correct points are being checked and that it resides within the bounds of the array
	while (checkRow < -1 || checkCol < -1)
	{
		++checkRow;
		++checkCol;
	}

	for (int i = 0; i < COL; i++)
	{
		checkRow++;
		checkCol++;
		// if it goes above the bounds of the array without finding a win condition exits
		if (checkRow >= ROW || checkCol >= COL)
			return false;
		else if (board[checkRow][checkCol] == board[checkRow - 1][checkCol - 1] && board[checkRow][checkCol] != '.')
			counter++;
		else
			counter = 0;
		if (counter == 3)
			return true;
	} // end i
	return false;
} // end checkRightDiagonal()

bool checkLeftDiagonal(int col, int row, const char board[ROW][COL])
{
	int counter = 0;
	int checkRow = row - 4;
	int checkCol = col + 4;

	while (checkRow < 0 || checkCol >= COL)
	{
		++checkRow;
		--checkCol;
	}

	for (int i = 0; i < COL; i++)
	{
		checkRow++;
		checkCol--;
		if (checkRow < 0 || checkCol >= COL)
			return false;
		if (board[checkRow][checkCol] == board[checkRow - 1][checkCol + 1] && board[checkRow][checkCol] != '.')
			counter++;
		else
			counter = 0;
		if (counter == 3)
			return true;
	} // end i
	return false;
} // end checkLeftDiagonal

void printBoard(const char board[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
			cout << board[i][j] << " ";
		cout << endl;
	} // end i
	for (int i = 0; i < COL; i++)
		cout << i + 1 << " ";
	cout << endl;
} // end printBoard()

void boardReset(char board[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
			board[i][j] = '.';
	}
} // end boardReset()

bool validEntry(char board[ROW][COL], int col, int playerTurn)
{
	if (col >= 0 && col < COL)
	{
		char playerNum = (playerTurn == 1) ? 'x' : 'o';

		for (int i = ROW; i > 0; i--)
		{
			if (board[i - 1][col] == '.')
			{
				board[i - 1][col] = playerNum;
				return true;
			}
		} // end i
	} // end col bound check
	return false;
} // end validEntry()

bool draw(const char board[ROW][COL])
{
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			if (board[i][j] == '.')
				return false;
		}
	} // end i
	return true;
} // end draw()