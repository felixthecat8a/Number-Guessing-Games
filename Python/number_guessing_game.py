#using Python
import random

start_game = "Guess the number between 1 and 100."
print(start_game)

number = random.randrange(1,100)
#print("the number is {:d}" .format(number)) #for debugging

first_try = "Guess the number: "
guess = int(input(first_try))

new_try = "Try again: "
too_low = "Your number is too low."
too_high = "Your number is too high."

attempts = 1

while number!= guess:
    attempts = attempts + 1
    if guess < number:
        print(too_low)
        guess = int(input(new_try))
    elif guess > number:
        print(too_high)
        guess = int(input(new_try))
    else:
      break

if attempts == 1:
    tries = "attempt"
else: 
    tries = "attempts"

win_game = "You guessed it right!!"
print(win_game)
print("It only took you {:d} {}. :)".format(attempts,tries))
