/*
Downs, Josh
Summer - 2017
*/

#include "Mancala.h"
#include <sstream>

void mancala()
{
	int board[MANCALA_SIZE];
	resetBoard(board);

	cout << "//////////////////////////////////////////////////" << endl
		<< "//                                              //" << endl
		<< "//                                              //" << endl
		<< "//             Welcome to Mancala!              //" << endl
		<< "//                                              //" << endl
		<< "//                                              //" << endl
		<< "//////////////////////////////////////////////////" << endl
		<< endl
		<< "Do you need to know the rules of Mancala? " << endl
		<< "1. Yes" << endl
		<< "2. No" << endl;
	int response;
	cin >> response;
	if (response == 1) printRules();

	cout << "The starting board is:" << endl << endl;

	bool endOfGame = false;
	int playerTurn = 1;

	while (!endOfGame)
	{
		printBoard(board);

		cout << "Player " << playerTurn << " select move: ";
		int move;
		cin >> move;
		cout << endl;
		if (validEntry(board, playerTurn, move))
		{
			int i = board[move];
			board[move] = 0;
			while (i > 0)
			{
				// Immediately increments so a marble does not get
				// dropped in the place it was picked up from
				++move;

				// Skips the opposing players stash 
				// instead of placing a marble in it
				if (move == 14 && playerTurn == 1 || move == 7 && playerTurn == 2)
					++move;

				// Allows the board to wrap around
				move %= 14;
				++board[move];
				--i;
			} // end moving pieces

			// Checks to see if the opposite side is captured
			if (playerTurn == 1 && board[move] == 1 && move > 0 && move < 7
				|| playerTurn == 2 && board[move] == 1 && move > 7 && move < 14)
				captureOpposite(board, playerTurn, move);

			// Changes the current players turn if they end anywhere but their capture
			if (move != 7 && playerTurn == 1
				|| move != 0 && playerTurn == 2)
				playerTurn = playerTurn % 2 + 1;
		} // end validEntry() check
		else
			cout << "Invalid entry, try again." << endl << endl;
		endOfGame = winCondition(board);
	} // end endOfGame loop

	/*
	Once the game ends one side will be empty so all the opposing side pieces
	will need to be moved into the correct capture.
	The loop makes sure pieces 1-6 go into player 1s capture
	and pieces 7-13 go into player 2s capture
	*/
	for (int i = 1; i < MANCALA_SIZE; ++i)
	{
		if (i < 7)
		{
			board[7] += board[i];
			board[i] = 0;
		}
		else if (i > 7)
		{
			board[0] += board[i];
			board[i] = 0;
		}
	} // end totaling up score loop

	cout << "The final board is: " << endl;
	printBoard(board);
	cout << "The winer is: ";
	cout << ((board[0] > board[7]) ? "Player 2!" : "Player 1!") << endl << endl;

} // end mancala()

bool validEntry(const int *board, int playerTurn, int selection)
{
	switch (playerTurn)
	{
	case 1: return (board[selection] != 0 && selection > 0 && selection < 7);
		break;
	case 2: return (board[selection] != 0 && selection > 7 && selection < 14);
		break;
	default: return false;
	} // end switch
} // end validEntry()

void printBoard(const int *board)
{
	cout << "            Player 2 Side           " << endl
		<< "       13  12  11  10   9   8       " << endl
		<< "------------------------------------" << endl
		<< "|    | " << setw(2) << setfill('0') << board[13] << "  " << setw(2)
		<< setfill('0') << board[12] << "  " << setw(2) << setfill('0') << board[11]
		<< "  " << setw(2) << setfill('0') << board[10] << "  " << setw(2)
		<< setfill('0') << board[9] << "  " << setw(2) << setfill('0') << board[8]
		<< " |    |" << endl
		<< "| " << setw(2) << setfill('0') << board[0] << " |                        | "
		<< setw(2) << setfill('0') << board[7] << " |" << endl
		<< "|    | " << setw(2) << setfill('0') << board[1] << "  " << setw(2)
		<< setfill('0') << board[2] << "  " << setw(2) << setfill('0') << board[3]
		<< "  " << setw(2) << setfill('0') << board[4] << "  " << setw(2) << setfill('0')
		<< board[5] << "  " << setw(2) << setfill('0') << board[6] << " |    |" << endl
		<< "------------------------------------" << endl
		<< "        1   2   3   4   5   6       " << endl
		<< "            Player 1 Side           " << endl << endl;
} //end printBoard()

void resetBoard(int *board)
{
	for (int i = 0; i < MANCALA_SIZE; ++i)
	{
		board[i] = 4;
		//sets captures to 0
		board[0] = 0;
		board[7] = 0;
	}

} // end resetBoard()

void printRules()
{
	cout << endl << "\t\t\tHow to Play" << endl
		<< "-----------------------------------------------------------------------------" << endl << endl
		<< "The Mancala board is made up of two rows of six holes (or pits) each." << endl
		<< "Four marbles are placed in each hole." << endl
		<< "Each player has a store to the right side of the Mancala board." << endl
		<< "The game begins with one player picking up all of the pieces in any one of the holes on his side." << endl
		<< "Moving counter-clockwise, one marble will be deposited in each hole until they run out." << endl
		<< "If you run into your own store, one piece will be deposited in it." << endl
		<< "If you run into your opponent's store, it will be skipped." << endl
		<< "If the last piece lands in your own store, you get a free turn." << endl
		<< "If the last piece dropped is in an empty hole on your side, you capture" << endl
		<< "that piece and any pieces in the hole directly opposite." << endl
		<< "Captured pieces are placed in your store." << endl
		<< "The game ends when all six spaces on one side of the Mancala board are empty." << endl
		<< "The player who still has pieces on his side of the board when the game ends captures all of those pieces." << endl
		<< "The victor will be determined by counting all the pieces in each store." << endl
		<< "Whoever has the most wins!" << endl << endl;
} // end printRules()

void captureOpposite(int *board, int playerTurn, int move)
{
	int steal = 0;
	if (playerTurn == 1)
	{
		switch (move)
		{
		case 1: 
			steal = board[13];
			board[13] = 0;
			break;
		case 2: 
			steal = board[12];
			board[12] = 0;
			break;
		case 3: 
			steal = board[11];
			board[11] = 0;
			break;
		case 4:
			steal = board[10];
			board[10] = 0;
			break;
		case 5:
			steal = board[9];
			board[9] = 0;
			break;
		case 6:
			steal = board[8];
			board[8] = 0;
			break;
		} // end player 1 switch
	}
	else
	{
		switch (move)
		{
		case 13:
			steal = board[1];
			board[1] = 0;
			break;
		case 12:
			steal = board[2];
			board[2] = 0;
			break;
		case 11:
			steal = board[3];
			board[3] = 0;
			break;
		case 10:
			steal = board[4];
			board[4] = 0;
			break;
		case 9:
			steal = board[5];
			board[5] = 0;
			break;
		case 8:
			steal = board[6];
			board[6] = 0;
			break;
		} // end player 2 switch
	} // end playerTurn if/else
	int capture = (playerTurn == 1) ? 7 : 0;

	if (steal != 0)
	{
		// The +1 accounts for the marble that initiated the steal
		board[capture] += steal + 1;
		board[move] = 0;
	}
} // end captureOpposite()

bool winCondition(int *board)
{
	return (board[1] == board[2] && board[2] == board[3] 
		&& board[3] == board[4] && board[4] == board[5] && 
		board[5] == board[6] && board[6] == 0
		|| board[8] == board[9] && board[9] == board[10] &&
		board[10] == board[11] && board[11] == board[12] &&
		board[12] == board[13] && board[13] == 0);
} // end winCondition