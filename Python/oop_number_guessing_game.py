#using Python
import random

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
        
    def start(self):
        self.answer = int(random.randrange(1,100))
        #print("the number is {:d}" .format(self.answer)) #for debugging

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
        print(f"It only took you {self.attempts} {self.tries()}. :)")

    def tries(self):
        if self.attempts == 1:
            return " try"
        else:
            return" tries"

    def game(self):
        self.start()
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

if __name__ == '__main__':
    active = True
    while(active):
        play = Guess()
        play.game()
        prompt_message = "Do you want to play again? (y/n): "
        yes_or_no = input(prompt_message).lower()
        if yes_or_no == "yes" or yes_or_no == "y":
            continue
        elif yes_or_no == "no" or yes_or_no == "n":
            print("Goodbye :)")
            break
        else: 
            print('Invalid Response - Exiting Game')
            break
