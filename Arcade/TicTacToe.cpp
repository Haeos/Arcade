/*
Downs, Josh
Summer - 2017
*/

#include "TicTacToe.h"

void ticTacToe()
{
	char board[TTT_SIZE][TTT_SIZE];
	boardReset(board);

	cout << "//////////////////////////////////////////////////" << endl
		<< "//           Welcome to Tic Tac Toe!            //" << endl
		<< "//                                              //" << endl
		<< "//   The first player to connect three wins!    //" << endl
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
		tie = draw(board);
		printBoard(board);
		cout << endl;

		cout << "Player " << playerTurn << " select your column: ";
		int col;
		cin >> col;
		cout << "Select your row: ";
		int row;
		cin >> row;

		// decrementing variables accounts for 0 based system
		if (validEntry(board, --col, --row, playerTurn))
		{
			playerTurn = playerTurn % 2 + 1;

			// Checking for win condition
			endOfGame = checkWin(board, col, row);
		}
		else
		{
			cout << endl << "Invalid entry detected, please try again"
				<< endl << endl;
		}
	}
	printBoard(board);

	playerTurn = playerTurn % 2 + 1;
	if (!tie)
		cout << endl << "Congratulations Player " << playerTurn
		<< " you are the winner!" << endl << endl;
	else
		cout << endl << "It's a tie!" << endl << endl;
}
bool checkWin(const char board[TTT_SIZE][TTT_SIZE], int col, int row)
{
	bool diagonal = false;
	if (col % 2 == 0 && row % 2 == 0 || (col == row && row == 1))
		diagonal = ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '.')
			|| (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != '.'));
	return (diagonal || (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != '.')
		|| (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != '.'));
}

// Displays the current board
void printBoard(const char board[TTT_SIZE][TTT_SIZE])
{
	cout << "  ";
	for (int i = 0; i < TTT_SIZE; i++)
	{
		cout << i + 1 << " ";
	}
	cout << endl;

	for (int i = 0; i < TTT_SIZE; i++)
	{
		cout << i + 1 << " ";
		for (int j = 0; j < TTT_SIZE; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
	
	cout << endl;
}

// Resets the board to the beginning state
void boardReset(char board[TTT_SIZE][TTT_SIZE])
{
	for (int i = 0; i < TTT_SIZE; i++)
	{
		for (int j = 0; j < TTT_SIZE; j++)
			board[i][j] = '.';
	}
}

bool validEntry(char board[TTT_SIZE][TTT_SIZE], int col, int row, int playerTurn)
{
	if (col >= 0 && col < TTT_SIZE && board[row][col] == '.')
	{
		char playerNum = (playerTurn == 1) ? 'x' : 'o';
		board[row][col] = playerNum;
		return true;
	}
	return false;
}

bool draw(const char board[TTT_SIZE][TTT_SIZE])
{
	for (int i = 0; i < TTT_SIZE; ++i)
	{
		for (int j = 0; j < TTT_SIZE; ++j)
		{
			if (board[i][j] == '.')
				return false;
		}
	}
	return true;
}