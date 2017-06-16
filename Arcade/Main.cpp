/*
Downs, Josh
Summer - 2017
*/

#include <string>
#include <iostream>

#include "ConnectFour.h"
#include "TicTacToe.h"
#include "Mancala.h"
#include "MemoryMatch.h"
#include "Hangman.h"

const int QUIT = 6;

using namespace std;

int main()
{
	int gameSelection = 0;

	while (gameSelection != QUIT)
	{
		cout << "Which game would you like to play?" << endl
			<< "1. Connect Four" << endl
			<< "2. Tic Tac Toe" << endl
			<< "3. Mancala" << endl
			<< "4. Memory Match" << endl
			<< "5. Hangman" << endl
			<< QUIT << ". Quit" << endl;
		
		cin >> gameSelection;

		switch (gameSelection)
		{
		case 1: connectFour();
			break;
		case 2: ticTacToe();
			break;
		case 3: mancala();
			break;
		case 4: memoryMatch();
			break;
		case 5: hangman();
			break;
		case QUIT: cout << "Thanks for playing, hope to see you again soon!" << endl;
			break;
		default: cout << "Invalid Entry, try again." << endl;
		}
	}

	cout << endl;
	system("pause");
	return 0;
}