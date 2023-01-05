#using Python
import random
number = int(random.randrange(1,100))

class Guess:
    def __init__(self,number):
        self.answer = int(number)
        self.attempts = 1
        self.start_game = "Guess the number between 1 and 100."
        self.first_try = "Guess the number: "
        self.new_try = "Try again: "
        self.low = "Your number is too low."
        self.high = "Your number is too high."
        self.correct = "You guessed it right!!"

    def too_low(self):
        print(self.low)
        guess = int(input(self.new_try))
        return guess

    def too_high(self):
        print(self.high)
        guess = int(input(self.new_try))
        return guess

    def win(self):
        print("You guessed it right!!")
        if self.attempts == 1:
            print("It only took you ",self.attempts," try. :)")
        else:
            print("It only took you ",self.attempts," tries. :)")

    def game(self):
        print(self.start_game)
        self.guess = int(input(self.first_try))
        while self.answer!= self.guess:
            self.attempts = self.attempts + 1
            if self.guess < self.answer: 
                self.guess = self.too_low()
            elif self.guess > self.answer: 
                self.guess = self.too_high()
            else: break
        self.win()

play = Guess(number)
play.game()
