/* using C++ */
#include <iostream> // for std::cout, std::cin & std::streamsize
#include <string> // for std::string & std::to_string()
#include <limits> // for std::numeric_limits
#include <cctype> // for tolower()
#include <cstdlib> // for std::exit()
#include <random> // for random number generation

//#define DEBUG // uncomment to help with debugging

class NumberGuessingGame {
	private:
	const int MIN = 1, MAX = 100;
	const int MAX_ATTEMPTS = 5;
	int randNum, guessNum;
	int attempts = 0;
	std::default_random_engine generator;

	public:
	NumberGuessingGame() {
		std::random_device rd;
		generator.seed(rd());
	}

	void createRandomNumber() {
		std::uniform_int_distribution<int> dist(MIN, MAX);
		randNum = dist(generator);
		#ifdef DEBUG
			std::cout << "Answer: " << randNum << std::endl;
		#endif
	}

	void playGame() {
		std::string intro = std::to_string(MAX_ATTEMPTS) + " attempts or less.";
		std::cout << "Guess the number between 1 and 100 in " << intro << std::endl;
		createRandomNumber();
		std::cout << "\nGuess the number: ";
		do {
			attempts++;
			checkLimit();
			std::cin >> guessNum;
			checkInput();
			if (guessNum < randNum) {
				std::cout << "Your number is too low.\nTry Again: ";
				continue;
			} else if (guessNum > randNum) {
				std::cout << "Your number is too high.\nTry Again: ";
				continue;
			}
		} while (guessNum != randNum);
		std::string guessCorrectString = "You guessed it right!!!\n";
		std::string tries = (attempts == 1) ? " attempt. :)" : " attempts. :)";
		std::cout << guessCorrectString << "It only took " << attempts << tries << std::endl;
		playAgain();
	}

	void checkLimit() {
		if (attempts > MAX_ATTEMPTS) {
			std::cout << "Sorry, you've reached " << MAX_ATTEMPTS << " tries. :(" << std::endl;
			std::cout << "The number was " << randNum << "." << std::endl;
			playAgain();
		}
	}

	void checkInput() {
    	int invalidInputCount = 0;
		while (std::cin.fail()) {
			invalidInputCount++;
			if (invalidInputCount >= 3) {
				std::cout << "Invalid Inputs Exceeded - Exiting Game" << std::endl;
				std::exit(0);
			}
			std::cout << "Invalid input. Please enter an integer.\nTry Again: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> guessNum;
		}
	}

	void playAgain() {
		char playAgainInput;
		int invalidInputCount = 0;
		std::cout << "Do you want to play again?\n(y/n): ";
		while (true) {
			std::cin >> playAgainInput;
			playAgainInput = tolower(playAgainInput);
			if (playAgainInput == 'y') {
				attempts = 0;
				std::cin.clear();
				playGame();
			}
			else if (playAgainInput == 'n') {
				std::cout << "Goodbye. :)" << std::endl;
				std::cin.ignore();
				std::cin.get();
				std::exit(0);
			} else {
				invalidInputCount++;
				if (invalidInputCount >=3) {
					std::cout << "Invalid Inputs Exceeded - Exiting Game" << std::endl;
					std::exit(0);
				}
				std::cout << "Invalid input. Please enter 'y' or 'n'.\n(y/n): ";
			}
		}
	}
};

int main() {
	NumberGuessingGame gameObj;
	gameObj.playGame();
	//system("pause>0");
	return 0;
}
