#using Python
import random

debug = True #set True to debug

start_game = "Guess the number between 1 and 100."
print(start_game)

number = random.randrange(1,100)
if debug:
    print("Answer: {:d}" .format(number)) 

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
    elif guess > number:
        print(too_high)
    guess = int(input(new_try))

if attempts == 1:
    tries = "attempt"
else: 
    tries = "attempts"

win_game = "You guessed it right!!"
print(win_game)
print(f"It only took {attempts} {tries}. :)")
