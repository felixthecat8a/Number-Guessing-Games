import random

class NumberGuessingGame:
    def __init__(self):
        self.debug = True #set True to debug
        self.attempts = 0
        self.maxAttempts = 5
        
    def start(self):
        attemptPrompt = ("in {:d} tries or less." .format(self.maxAttempts))
        print(f"Guess the number between 1 and 100 {attemptPrompt}")
        MIN_NUMBER = 1
        MAX_NUMBER = 100
        self.answer = int(random.randrange(MIN_NUMBER,MAX_NUMBER))
        if self.debug:
            print(f"Answer: {self.answer}")
        self.game()

    def game(self):
        self.guess = int(input("Guess the number: "))
        self.play()
        self.play_again()

    def play(self):
        self.attempts += 1
        while self.guess != self.answer:
            if self.attempts >= self.maxAttempts:
                print(f"Sorry, you've reached {self.maxAttempts} tries.")
                print(f"The number was {self.answer}")
                return
            self.check()
            self.guess = int(input("Try again: "))
        print("You guessed it right!!")
        print(f"It only took {self.attempts} {self.tries()}. :)")

    def check(self):
        self.attempts += 1
        if self.guess < self.answer:
            print("Your number is too low.")
        elif self.guess > self.answer:
            print("Your number is too high.")
        return

    def tries(self):
        if self.attempts == 1:
            return "try"
        else:
            return "tries"

    def play_again(self):
        i = 0
        while(i < 3):
            prompt_message = "Do you want to play again? (y/n): "
            yes_or_no = input(prompt_message).lower()
            if yes_or_no == "yes" or yes_or_no == "y":
                self.attempts = 0
                self.start()
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
    NumberGuessingGame().start()
