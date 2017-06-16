/*
Downs, Josh
Summer - 2017
*/

#include "MemoryMatch.h"

void memoryMatch()
{
	char masterBoard[MEMORYMATCH_SIZE][MEMORYMATCH_SIZE];
	char board[MEMORYMATCH_SIZE][MEMORYMATCH_SIZE];
	resetBoards(board, masterBoard);

	cout << "//////////////////////////////////////////////////" << endl
		<< "//                                              //" << endl
		<< "//          Welcome to Memory Match!            //" << endl
		<< "//                                              //" << endl
		<< "//       Turn over cards to until all of        //" << endl
		<< "//     the possible matches have been found     //" << endl
		<< "//                                              //" << endl
		<< "//////////////////////////////////////////////////" << endl
		<< endl;

	bool endOfGame = false;
	while (!endOfGame)
	{
		cout << "The current board is:" << endl << endl;
		printBoard(board);

		cout << endl << "Enter the column for the first selection: ";
		int col1, row1;
		cin >> col1;
		cout << "Enter the row for the first selection: ";
		cin >> row1;

		if (validEntry(board, --col1, --row1))
		{
			board[row1][col1] = masterBoard[row1][col1];
			cout << endl;
			printBoard(board);
			cout << endl;

			int col2, row2;
			int counter = 0;
			do
			{
				if (counter != 0)
					cout << endl << "Invalid entry, try again" << endl << endl;

				cout << endl << "Enter the column for the second selection: ";
				cin >> col2;
				cout << "Enter the row for the first selection: ";
				cin >> row2;

				++counter;
			}while (!validEntry(board, --col2, --row2));

			board[row2][col2] = masterBoard[row2][col2];
			cout << endl;
			printBoard(board);
			cout << endl;

			system("pause");

			if (matchFound(masterBoard, col1, row1, col2, row2))
			{
				cout << endl << "You have found a match :)" << endl << endl;
				board[row1][col1] = ' ';
				board[row2][col2] = ' ';
			}
			else
			{
				cout << endl << "No match found :(" << endl << endl;
				board[row1][col1] = '.';
				board[row2][col2] = '.';
			}

		} // end col1 row1 valid entry check
		else
			cout << endl << "Invalid entry, try again" << endl << endl;

		endOfGame = gameOver(board);
	} // end endOfGame loop
	
	cout << endl << "You have found all possible matches, good work!" << endl << endl;
} // end memoryMatch

void printBoard(const char board[][MEMORYMATCH_SIZE])
{
	// Numbering above the columns
	cout << "   ";
	for (int j = 1; j <= MEMORYMATCH_SIZE; ++j)
		cout << j << "  ";
	cout << endl;

	for (int i = 0; i < MEMORYMATCH_SIZE; ++i)
	{
		cout << i + 1 << "  "; // numbering for rows
		for (int j = 0; j < MEMORYMATCH_SIZE; ++j)
			cout << board[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
} // end printBoard()

void resetBoards(char board[][MEMORYMATCH_SIZE], 
	char masterBoard[][MEMORYMATCH_SIZE])
{
	char tempArray[] = { 'A', 'A', 'B', 'B', 'C', 'C', 'D', 'D',
	'E', 'E', 'F', 'F', 'G', 'G', 'H', 'H', 'I', 'I', 'J', 'J', 'K', 'K', 
	'L', 'L', 'M', 'M', 'N', 'N', 'O', 'O', 'P', 'P', 'Q', 'Q', 'R', 'R'};

	int k = 0;
	for (int i = 0; i < MEMORYMATCH_SIZE; ++i)
	{
		for (int j = 0; j < MEMORYMATCH_SIZE; ++j)
		{
			masterBoard[i][j] = tempArray[k++];
			board[i][j] = '.';
		}
	}

	// obtain a time-based seed: (from cplusplus.com)
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	// Randomize and shuffle it based off the unique seed
	shuffle(&masterBoard[0][0], 
		&masterBoard[MEMORYMATCH_SIZE - 1][MEMORYMATCH_SIZE - 1], 
		default_random_engine(seed));
} // end resetBoards()

bool validEntry(const char board[][MEMORYMATCH_SIZE], int col, int row)
{
	return (col >= 0 && col < MEMORYMATCH_SIZE
		&& row >= 0 && row < MEMORYMATCH_SIZE
		&& board[row][col] != ' ');
} // end validEntry()

bool matchFound(const char masterBoard[][MEMORYMATCH_SIZE],
	int col1, int row1, int col2, int row2)
{
	return (masterBoard[row1][col1] == masterBoard[row2][col2] &&
		!(row1 == row2 && col1 == col2));
} // end matchFound()

bool gameOver(const char board[][MEMORYMATCH_SIZE])
{
	for (int i = 0; i < MEMORYMATCH_SIZE; ++i)
	{
		for (int j = 0; j < MEMORYMATCH_SIZE; ++j)
		{
			if (board[i][j] != ' ')
				return false;
		} // end j
	} // end i
	return true;
} // end gameOver()