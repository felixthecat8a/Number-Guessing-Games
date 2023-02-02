//Using C++
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class NumberGuessingGame {
	private:
	const int MIN = 1;
	const int MAX = 100;
	int randNum, guessNum;
	int attempts = 0;
	const string gameIntro = "Guess the number between 1 and 100 in less than ten attempts.";
	const string firstGuess = "Guess the number: ";
	const string tooLow = "Your number is too low.\nTry Again: ";
	const string tooHigh = "Your number is too high.\nTry Again: ";
	const string correct = "You guessed it right!!\n";
	char y_or_n;
	bool debug = true; //set true to debug

	public:
	void createAnswer() {
		srand(time(0));
		randNum = (rand() % MAX) + MIN;
		if (debug) {
			cout << "\nAnswer: " << randNum << endl;
		}
	}

	void startGame() {
		cout << gameIntro << endl;
		createAnswer();
		cout << firstGuess << endl;
	}

	void playGame() {
		startGame();
		checkAnswer();
		playAgain();
	}

	void checkAnswer() {
		do {
			if (attempts == 10) {
				cout << "Sorry, you've reached the limit of 10 tries.";
				playAgain();
			}
			cin >> guessNum;
			attempts++;
			if (guessNum < randNum)
				low();
			else if (guessNum > randNum)
				high();
		} while (guessNum != randNum);
		win();
	}

	void low() {
		cout << tooLow << endl;
	}

	void high() {
		cout << tooHigh << endl;
	}

	void win() {
		string tries;
		if (attempts == 1) {
			tries = "attempt. :)";
		} else {
			tries = "attempts. :)";
		}
		cout << correct << "It only took " << attempts << tries << endl;
	}

	void playAgain() {
		string prompt = "Do you want to play again?\n(y/n): ";
		int i = 0;
		bool message = true;
		while (i < 3) {
			cout << prompt << endl;
			cin >> y_or_n;
			y_or_n = tolower(y_or_n);
			if (y_or_n == 'y') {
				attempts = 0;
				playGame();
				message = false;
				break;
			}
			else if (y_or_n == 'n') {
				cout << "Goodbye. :)" << endl;
				message = false;
				break;
			} else {
				cout << "Invalid Input - Please enter \"y\" or \"n\"." << endl;
				i++;
				message = true;
				continue;
			}
		}
		if (message) {
			cout << "Too Many Invalid Inputs - Exiting Game" << endl;
			exit (EXIT_FAILURE);
		}
		exit (EXIT_SUCCESS);
	}
};

int main() {
	NumberGuessingGame gameObj;

	gameObj.playGame();

	system("pause>0");
}
