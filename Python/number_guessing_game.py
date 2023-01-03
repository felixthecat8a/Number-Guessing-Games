#using Python
import random

start_game = "Guess the number between 1 and 100."
print(start_game)

number = random.randrange(1,100)

first_try = "Guess the number: "
guess = int(input(first_try))

attempts = 0

while number!= guess:
    attempts = attempts + 1
    if guess < number:
        print("Your number is too low.")
        guess = int(input("Try again: "))
    elif guess > number:
        print("Your number is too high.")
        guess = int(input("Try again: "))
    else:
      break

print("You guessed it right!!")
print("It only took you ",attempts," attempts. :)")
