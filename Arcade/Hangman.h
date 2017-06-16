/*
Downs, Josh
Summer - 2017
*/

#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;

// @descrip - Begins the game of hangman
void hangman();

// @descrip - Prints the board for hangman
void printHangman(const string& guessWord, 
	const string& usedLetters, int bodyCount);

/*
@descrip - gets a random word from a seeded list
@param const vector<string>& - list of all potential words
@return - random string word for that hangman session
*/
string getRandomWord(const vector<string>& wordVector);

/*
@descrip - checks to see if the guessed letter is in the correctWord
@param const string& correctWord - solution for the round of hangman
@param string& guessWord - unrevealed word the user is guessing with
@param char guessLetter - user's current guess
@return - true if the letter is found, false otherwise
*/
bool letterFound(const string& correctWord, 
	string& guessWord, char guessLetter);

/*
@descrip - checks to see if the letter has already been guessed
@param const string& usedLetters - list of letters used
@param char guessLetter - user's current guess
@return - true if the letter has been used, false otherwise
*/
bool alreadyGuessed(const string& usedLetters, char guessLetter);

/*
@descrip - chooses a random number between minVal and maxVal
@param int minVal - smallest possible number allowed
@param int maxVal - largest possible number allowed
@return - randomized integer
*/
int getRandomNumber(int minVal, int maxVal);

#endif