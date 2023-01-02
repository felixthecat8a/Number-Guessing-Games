#using Python
import random
number = int(random.randrange(1,100))

class Guess:
    def __init__(self,number):
        self.answer = int(number)
        self.attempts = 1

    def too_low(self):
        print("Your number is too low.")
        guess = int(input("Try again: "))
        return guess

    def too_high(self):
        print("Your number is too high.")
        guess = int(input("Try again: "))
        return guess

    def win(self):
        print("You guessed it right!!")
        print("It only took you ",self.attempts," attempts. :)")

    def game(self):
        print("Guess the number between 1 and 100.")
        self.guess = int(input("Guess the number: "))
        while self.answer!= self.guess:
            self.attempts = self.attempts + 1
            if self.guess < self.answer: 
                self.guess = self.too_low()
            elif self.guess > self.answer: 
                self.guess = self.too_high()
            else: break
        self.win()

n = Guess(number)
n.game()
