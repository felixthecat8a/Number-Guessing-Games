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
	
    cout << "Guess the number between 1 and 100.\n";
	cout << "Guess the number: ";

	do {
		cin >> guess;
		attempts++;

		if (guess > answer)
			cout << "Your number is too high.\nTry Again: ";
		else if (guess < answer)
			cout << "Your number is too low.\nTry Again: ";
		else
            cout << "You guessed it right!!\nIt only took you " << attempts << " attempts. :)\n";
	} while (guess != answer);

	system("pause>0");
}
