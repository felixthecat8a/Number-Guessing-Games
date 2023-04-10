//Using C++
#include <iostream> // for std::cout, std::cin & std::streamsize
#include <string> // for std::string & std::to_string()
#include <cstdlib> // for rand() & srand()
#include <ctime> // for time()
using namespace std;

class NumberGuessingGame {
	private:
	const int MIN = 1;
	const int MAX = 100;
	int randNum, guessNum;
	int attempts = 0;
	int maxAttempts = 10;
	const string attemptIntro = " in " + std::to_string(maxAttempts) + " attempts or less.";
	const string gameIntro = "Guess the number between 1 and 100" + attemptIntro;
	const string firstGuess = "Guess the number: ";
	const string tooLow = "Your number is too low.\nTry Again: ";
	const string tooHigh = "Your number is too high.\nTry Again: ";
	const string correct = "You guessed it right!!\n";
	char playAgainInput;
	bool debug = true; //set true to debug

	public:
	void createAnswer() {
		srand(time(0));
		randNum = (rand() % MAX) + MIN;
		if (debug) {
			cout << "Answer: " << randNum << endl;
		}
	}

	void startGame() {
		cout << gameIntro << endl;
		createAnswer();
		cout << firstGuess;
		playGame();
	}

	void playGame() {
		cin >> guessNum;
		checkAnswer();
		playAgain();
	}

	void checkAnswer() {
		do {
			checkLimit();
			checkInput();
			attempts++;
			if (guessNum < randNum) {
				cout << tooLow;
				cin >> guessNum;
			} else if (guessNum > randNum) {
				cout << tooHigh;
				cin >> guessNum;
			}
		} while (guessNum != randNum);
		win();
	}

	void checkLimit() {
		if (attempts >= maxAttempts) {
			string attemptPrompt = std::to_string(maxAttempts) + " tries.";
			string limitPrompt = "Sorry, you've reached " + attemptPrompt;
			cout << limitPrompt << endl;
			cout << "The number was " << randNum << "." << endl;
			playAgain();
		}
	}

	void checkInput() {
		while (std::cin.fail()) {
			cout << "Invalid input. Please enter an integer.\nTry Again: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> guessNum;
		}
	}

	void win() {
		string tries;
		if (attempts == 1) {
			tries = " attempt. :)";
		} else {
			tries = " attempts. :)";
		}
		cout << correct << "It only took " << attempts << tries << endl;
	}

	void playAgain() {
		string prompt = "Do you want to play again?\n(y/n): ";
		int i = 0;
		bool message = true;
		while (i < 3) {
			cout << prompt;
			cin >> playAgainInput;
			playAgainInput = tolower(playAgainInput);
			if (playAgainInput == 'y') {
				attempts = 0;
				startGame();
				message = false;
				break;
			}
			else if (playAgainInput == 'n') {
				cout << "Goodbye. :)" << endl;
				message = false;
				break;
			} else {
				cout << "Invalid Input. Please enter \"y\" or \"n\"." << endl;
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
	gameObj.startGame();
	system("pause>0");
}
