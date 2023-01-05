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
		const string gameIntro = "Guess the number between 1 and 100.\n";
		const string firstGuess = "Guess the number: ";
		const string tooLow = "Your number is too low.\nTry Again: ";
		const string tooHigh = "Your number is too high.\nTry Again: ";
		const string correct = "You guessed it right!!\n";

	public:

		void startGame() {
			cout << gameIntro << endl;
			cout << firstGuess;
		}

		void createAnswer() {
			srand(time(0));
			randNum = (rand() % MAX) + MIN; 
		}

		void playGame() {
			do {
				cin >> guessNum;
				attempts++;

				if (guessNum < randNum)
					low();
				else if (guessNum > randNum)
					high();
				else
					win();
			} while (guessNum != randNum);

		}

		void low() {
			cout << tooLow;
		}

		void high() {
			cout << tooHigh;
		}

		void win() {
			
			cout << correct << "It only took you " << attempts << " attempts. :)\n";
		}
};

int main() {
	NumberGuessingGame gameObj;

	gameObj.createAnswer();
	gameObj.startGame();
	gameObj.playGame();

	system("pause>0");
}
