//Using C++
#include <iostream> // for std::cout, std::cin & std::streamsize
#include <string> // for std::string & std::to_string()
#include <limits> // for std::numeric_limits
#include <cctype> // for tolower()
#include <random> // for random number generation
#include <chrono> // for high_resolution_clock

class NumberGuessingGame {
	private:
	bool debug = false; //set true to debug
	const int MIN = 1;
	const int MAX = 100;
	int randNum, guessNum;
	int attempts = 1; //start counting after first try
	int maxAttempts = 10;
	const std::string startIntro = std::to_string(MIN) + " and " + std::to_string(MAX);
	const std::string attemptIntro = " in " + std::to_string(maxAttempts) + " attempts or less.";
	const std::string gameIntro = "Guess the number between " + startIntro + attemptIntro;
	const std::string firstGuess = "Guess the number: ";
	char playAgainInput;

	public:
	void createAnswer() { 
		// Use high-resolution clock to generate a unique seed
		auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		std::mt19937 rng(seed); // Mersenne Twister random number engine
		std::uniform_int_distribution<int> dist(MIN, MAX);
		randNum = dist(rng); // generate random number
		if (debug) {
			std::cout << "\nAnswer: " << randNum << std::endl;
		}
	}

	void startGame() {
		std::cout << gameIntro << std::endl;
		createAnswer();
		std::cout << firstGuess;
		playGame();
	}

	void playGame() {
		std::cin >> guessNum;
		checkAnswer();
		playAgain();
	}

	void checkAnswer() {
		do {
			checkLimit();
			checkInput();
			if (guessNum < randNum) {
				tooLOW();
				continue;
			} else if (guessNum > randNum) {
				tooHIGH();
				continue;
			}
		} while (guessNum != randNum);
		win();
	}

	void checkLimit() {
		if (attempts >= maxAttempts) {
			std::string attemptPrompt = std::to_string(maxAttempts) + " tries. :(";
			std::string limitPrompt = "Sorry, you've reached " + attemptPrompt;
			std::cout << limitPrompt << std::endl;
			std::cout << "The number was " << randNum << "." << std::endl;
			playAgain();
		}
	}

	void checkInput() {
		while (std::cin.fail()) {
			std::cout << "Invalid input. Please enter an integer.\nTry Again: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> guessNum;
		}
	}

	void tooLOW() {
		std::string tooLow = "Your number is too low.\nTry Again: ";
		std::cout << tooLow;
		attempts++;
		std::cin >> guessNum;
	}

	void tooHIGH() {
		std::string tooHigh = "Your number is too high.\nTry Again: ";
		std::cout << tooHigh;
		attempts++;
		std::cin >> guessNum;
	}

	void win() {
		std::string correct = "You guessed it right!!!\n";
		std::string tries;
		if (attempts == 1) {
			tries = " attempt. :)";
		} else {
			tries = " attempts. :)";
		}
		std::cout << correct << "It only took " << attempts << tries << std::endl;
	}

	void playAgain() {
		std::string prompt = "Do you want to play again?\n(y/n): ";
		int i = 0;
		bool message = true;
		while (i < 3) {
			std::cout << prompt;
			std::cin >> playAgainInput;
			playAgainInput = tolower(playAgainInput);
			if (playAgainInput == 'y') {
				attempts = 0;
				startGame();
				message = false;
				break;
			}
			else if (playAgainInput == 'n') {
				std::cout << "Goodbye. :)" << std::endl;
				message = false;
				break;
			} else {
				std::cout << "Invalid Input. Please enter \"y\" or \"n\"." << std::endl;
				i++;
				message = true;
				continue;
			}
		}
		if (message) {
			std::cout << "Too Many Invalid Inputs - Exiting Game" << std::endl;
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
