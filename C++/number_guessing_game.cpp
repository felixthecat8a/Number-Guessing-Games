//Using C++
#include <iostream> // for std::cout & std::cin
#include <string> // for std::string & std::to_string()
#include <cstdlib> // for rand() & srand()
#include <ctime> // for time()
using namespace std;

int main() {
	const int MIN = 1;
	const int MAX = 100;
	int randNum, guessNum;
	int attempts = 0;
	bool debug = true; //set true to debug
	
	srand(time(0));
	randNum = (rand() % MAX) + MIN;
	if (debug) {
		cout << "Answer: " << randNum << endl;
	}
	
	const char startGame[] = "Guess the number between 1 and 100.";
	const char firstGuess[] = "Guess the number: ";

    cout << startGame << endl;
	cout << firstGuess;
	
	const string tooLow = "Your number is too low.\nTry Again: ";
	const string tooHigh = "Your number is too high.\nTry Again: ";
	const string correct = "You guessed it right!!\n";

	do {
		cin >> guessNum;
        attempts++;
        if (guessNum < randNum)
            cout << tooLow;
        else if (guessNum > randNum)
            cout << tooHigh;
    } while (guessNum != randNum);

	string tries = (attempts == 1) ? " attempt. :)" : " attempts. :)";

	cout << correct << "It only took you " << attempts << tries << endl;

	system("pause>0");
}
