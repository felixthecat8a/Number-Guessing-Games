//using C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	const int MIN = 1;
	const int MAX = 100;
	int answer, guess;
	int attempts = 0;
	
	srand(time(0));
	answer = (rand() % MAX) + MIN; 
	
    	printf("Guess the number between 1 and 100.\n");
	printf("Guess the number: ");

	do {
		scanf("%d",&guess);
		attempts++;

		if (guess > answer)
			printf("Your number is too high.\nTry Again: ");
		else if (guess < answer)
			printf("Your number is too low.\nTry Again: ");
		else
            		printf("You guessed it right!!\nIt only took you %d attempts. :)\n",attempts);
	} while (guess != answer);

	return 0;
}
