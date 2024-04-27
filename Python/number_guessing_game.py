#using Python
import random

start_game = "Guess the number between 1 and 100."
print(start_game)

number = random.randrange(1,100)

debug = True #set True to debug
if debug: print("Answer: {:d}" .format(number)) 

first_try = "Guess the number: "
guess = int(input(first_try))

attempts = 1

while number!= guess:
    attempts = attempts + 1
    if guess < number:
        print("Your number is too low.")
    else:
        print("Your number is too high.")
    guess = int(input("Try again: "))

if attempts == 1:
    tries = "attempt"
else:
    tries = "attempts"

print("You guessed it right!!")
print(f"It only took {attempts} {tries}. :)")
#print("It only took {:d} {}. :)".format(attempts,tries))
