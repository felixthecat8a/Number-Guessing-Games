//Using C++
#include <iostream>
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
	
	char startGame[] = "Guess the number between 1 and 100.\n";
	char firstGuess[] = "Guess the number: ";

    	cout << startGame << endl;
	cout << firstGuess;

	do {
		cin >> guess;
		attempts++;

		if (guess > answer)
			cout << "Your number is too high.\nTry Again: ";
		else if (guess < answer)
			cout << "Your number is too low.\nTry Again: ";
		else
            		cout << "You guessed it right!!\nIt only took you " << attempts << " attempts. :)" << endl;
	} while (guess != answer);

	system("pause>0");
}
