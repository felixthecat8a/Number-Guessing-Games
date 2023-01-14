#using Python
import random
debug = False #set True to debug

class Guess:
    def __init__(self):
        self.attempts = 1
        self.start_game = "Guess the number between 1 and 100."
        self.first_try = "Guess the number: "
        self.new_try = "Try again: "
        self.low = "Your number is too low."
        self.high = "Your number is too high."
        self.correct = "You guessed it right!!"

    def start(self):
        start_game = "Guess the number between 1 and 100."
        print(start_game)
        self.answer = int(random.randrange(1,100))
        if debug:
            print("the number is {:d}" .format(self.answer))
        print(self.start_game)
        self.guess = int(input(self.first_try))

    def check(self):
        while self.answer!= self.guess:
            self.attempts = self.attempts + 1
            if self.guess < self.answer: 
                self.guess = self.too_low()
            elif self.guess > self.answer: 
                self.guess = self.too_high()
        self.win()

    def too_low(self):
        print(self.low)
        guess = int(input(self.new_try))
        return guess

    def too_high(self):
        print(self.high)
        guess = int(input(self.new_try))
        return guess

    def win(self):
        print(self.correct)
        print(f"It only took you {self.attempts} {self.tries()}. :)")

    def tries(self):
        if self.attempts == 1:
            return "try"
        else:
            return"tries"

    def game(self):
        self.start()
        self.check()
        self.play_again()

    def play_again(self):
        i = 0
        while(i < 3):
            prompt_message = "Do you want to play again? (y/n): "
            yes_or_no = input(prompt_message).lower()
            if yes_or_no == "yes" or yes_or_no == "y":
                self.attempts = 1
                self.game()
                break
            elif yes_or_no == "no" or yes_or_no == "n":
                print("Goodbye :)")
                i = 0
                break
            else: 
                print('Invalid Response - Enter y or n.')
                i += 1
                continue
        if i > 0:
            print("Too Many Invalid Responses - Exiting Program")
                
if __name__ == '__main__':
    play = Guess()
    play.game()
