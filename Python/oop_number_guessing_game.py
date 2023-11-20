import random

class Guess:
    def __init__(self):
        self.debug = False #set True to debug
        self.attempts = 1
        self.start_game = "Guess the number between 1 and 100 in ten attemps or less."
        self.first_try = "Guess the number: "
        self.new_try = "Try again: "
        self.too_low = "Your number is too low."
        self.too_high = "Your number is too high."
        self.correct = "You guessed it right!!"

    def start(self):
        self.answer = int(random.randrange(1,100))
        if self.debug:
            print("the number is {:d}" .format(self.answer))
        print(self.start_game)
        self.guess = int(input(self.first_try))

    def check(self):
        while self.answer!= self.guess:
            if self.attempts >= 10:
                print("Sorry, you've reached the limit of 10 tries.")
                print(f"The number was {self.answer}")
                return
            self.attempts = self.attempts + 1
            if self.guess < self.answer: 
                print(self.too_low)
            elif self.guess > self.answer: 
                print(self.too_high)
            self.guess = int(input(self.new_try))
        print(self.correct)
        print(f"It only took {self.attempts} {self.tries()}. :)")

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
