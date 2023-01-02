#using Python
import random
print("Guess the number between 1 and 100.")
n = random.randrange(1,100)
guess = int(input("Guess the number: "))
attempts = 0
while n!= guess:
    attempts = attempts + 1
    if guess < n:
        print("Your number is too low.")
        guess = int(input("Try again: "))
    elif guess > n:
        print("Your number is too high.")
        guess = int(input("Try again: "))
    else:
      break
print("You guessed it right!!")
print("It only took you ",attempts," attempts. :)")
