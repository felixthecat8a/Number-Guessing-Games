//Using C++
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	const int MIN = 1;
	const int MAX = 100;
	int answer, guess;
	int attempts = 0;
	
	srand(time(0));
	answer = (rand() % MAX) + MIN; 
	
	const char startGame[] = "Guess the number between 1 and 100.\n";
	const char firstGuess[] = "Guess the number: ";
	
	const string tooLow = "Your number is too low.\nTry Again: ";
	const string tooHigh = "Your number is too high.\nTry Again: ";
	const string correct = "You guessed it right!!\n";

    	cout << startGame << endl;
	cout << firstGuess;

	do {
		cin >> guess;
		attempts++;

		if (guess < answer)
			cout << tooLow;
		else if (guess > answer)
			cout << tooHigh;
		else
            		cout << correct <<"It only took you " << attempts << " attempts. :)" << endl;
	} while (guess != answer);

	system("pause>0");
}
