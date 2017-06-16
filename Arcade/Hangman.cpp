/*
Downs, Josh
Summer - 2017
*/

#include "Hangman.h"

void hangman()
{
	vector<string> wordVector;
	wordVector.reserve(1100);

	ifstream input("hangman.txt");
	if (input)
	{
		string word;
		while (input >> word)
		{
			if (word != "") 
			{
				wordVector.push_back(word);
			}
		}
	}
	string correctWord, guessWord, usedLetters;
	correctWord = getRandomWord(wordVector);

	int i = 0;
	for (char c : correctWord)
	{
		guessWord += "-";
		correctWord[i++] = toupper(c);
	}

	/* 
	bodyCount keeps track of how many wrong guesses the user has made.
	If they reach 7 fails they are hanged to death.
	*/
	int bodyCount = 0;
	while (bodyCount < 7 && correctWord != guessWord)
	{
		printHangman(guessWord, usedLetters, bodyCount);

		cout << "Select a letter to guess: ";
		char guessLetter;
		cin >> guessLetter;
		guessLetter = toupper(guessLetter);

		if (alreadyGuessed(usedLetters, guessLetter))
			cout << "\nYou have guessed \"" << guessLetter << "\" before." << endl;
		else
		{
			// if not found it will return false - !false = true
			if (!letterFound(correctWord, guessWord, guessLetter))
			{
				++bodyCount;
				ostringstream out;
				out << usedLetters << " " << guessLetter;
				usedLetters = out.str();
			}
		} // end else alreadyGuessed() check
			
	} // end while

	if (correctWord == guessWord)
	{
		cout << "You were correct!  The word was: " 
			<< correctWord << endl;
	}
	else
	{
		cout << endl << "You have died." << endl
			<< "The word was: " << correctWord << endl
			<< "Better luck next time!" << endl;
	}
	cout << endl;
} // end hangman()

void printHangman(const string& guessWord, const string& usedLetters, int bodyCount)
{
	string head, upperBod, lowerBod, leftArm, rightArm,
		leftLeg, rightLeg;
	if (bodyCount-- > 0) head = "O"; 
	if (bodyCount-- > 0) leftArm = "\\";
	if (bodyCount-- > 0) upperBod = "|";
	if (bodyCount-- > 0) lowerBod = "|";
	if (bodyCount-- > 0) rightArm = "/";
	if (bodyCount-- > 0) leftLeg = "/";
	if (bodyCount-- > 0) rightLeg = "\\";
	cout
		<< "         ========" << endl
		<< "        ||      |" << endl
		<< "        ||      " << head << endl
		<< "        ||     " << leftArm << upperBod << rightArm <<  endl
		<< "        ||      " << lowerBod << endl
		<< "        ||     " << leftLeg << " " << rightLeg << endl
		<< "        ||       " << endl
		<< "    /========\\" << endl
		<< "  /============\\" << endl
		<< "/===============\\" << endl
		<< endl << endl;

	cout << "Solve this word: " << guessWord << endl;
	cout << "Letters used:" << usedLetters << endl << endl;
} // end printHangman()

string getRandomWord(const vector<string>& wordVector)
{
	return wordVector.at(getRandomNumber(0, wordVector.size() - 1));
} // end getRandomWord()

bool letterFound(const string& correctWord, string& guessWord,  char guessLetter)
{
	bool found = false;

	// counter is used to keep track of the replacement position
	int counter = 0;
	for (char c : correctWord)
	{
		if (c == guessLetter)
		{
			guessWord[counter] = guessLetter;
			// Do not return here in case of multiple instances of the letter
			found = true;
		}
		counter++;
	} // end for

	return found;
} // end letterFound()

bool alreadyGuessed(const string& usedLetters, char guessLetter)
{
	for (char c : usedLetters)
	{
		if (c == guessLetter)
			return true;
	}
	return false;
} // end alreadyGuessed()

int getRandomNumber(int minVal, int maxVal) 
{
	random_device r;
	default_random_engine eng(r());
	uniform_int_distribution<int> dist(minVal, maxVal);
	return dist(eng);
} // end getRandomNumber()