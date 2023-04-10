//Using C++
#include <iostream>
#include <string>
#include <random>
using namespace std;

int main()
{
	const int MIN = 1;
	const int MAX = 100;
	int answer, guess;
	int attempts = 0;
	bool debug = false; //set true to debug
	
	/*Mersenne Twister random number engine*/ 
	std::random_device rd; //seed
	std::mt19937 rng(rd()); 
	std::uniform_int_distribution<int> dist(MIN, MAX);
	answer = dist(rng);
	if (debug) {
		cout << "Answer: " << answer << endl;
	}
	
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
		
	} while (guess != answer);
	
	string tries = (attempts == 1) ? " attempt. :)" : " attempts. :)";

	cout << correct << "It only took " << attempts << tries << endl;
	
	system("pause>0");
}
