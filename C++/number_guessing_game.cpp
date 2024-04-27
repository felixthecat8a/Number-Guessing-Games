//Using C++
#include <iostream> // for std::cout & std::cin
#include <string> // for std::string
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

    	cout << "Guess the number between 1 and 100." << endl;
	cout <<  "Guess the number: ";

	do {
		cin >> guessNum;
        	attempts++;
        	if (guessNum < randNum)
            		cout << "Your number is too low.\nTry Again: ";
        	else if (guessNum > randNum)
            		cout << "Your number is too high.\nTry Again: ";
    	} while (guessNum != randNum);

	string tries = (attempts == 1) ? " attempt. :)" : " attempts. :)";

	cout << "You guessed it right!!" << endl;
	cout << "It only took " << attempts << tries << endl;

	system("pause>0");
}
