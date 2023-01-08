#using Elixir
defmodule NumberGuessingGame do
  def guess() do
     random = Enum.random(1..100)
     #IO.puts("Answer: #{random}") #for debugging
     IO.puts("Guess a number between 1 and 100.")
     first_guess = IO.gets("Guess the number: ")
     {first_guess, _} = Integer.parse(first_guess)
     attempts = 1
     guess_while(random,first_guess,attempts)
  end

  def guess_while(answer,number,attempts) do
    cond do
      number < answer ->
        too_low(answer,attempts)
      number > answer ->
        too_high(answer,attempts)
      number == answer ->
        win(attempts)
        play_again()
    end
  end

  def too_low(answer,a) do
    IO.puts("Your number is too low.")
    new_guess = IO.gets("Try again: ")
    {new_guess, _} = Integer.parse(new_guess)
    a = a + 1
    guess_while(answer,new_guess,a)
  end

  def too_high(answer,a) do
    IO.puts("Your number is too high.")
    new_guess = IO.gets("Try again: ")
    {new_guess, _} = Integer.parse(new_guess)
    a = a + 1
    guess_while(answer,new_guess,a)
  end
  
  def win(attempts) do
    IO.puts("You guessed it right!!")
    IO.puts("It only took you #{attempts} #{tries(attempts)}. :)")
  end

  def tries(attempts) do
    case 1 do
      ^attempts -> "try"
      _ -> "tries"
    end
  end
  
    def play_again() do
    yes_or_no = IO.gets("Do you want to play again? (y/n): ")
    cond do
      yes_or_no == "y\n" ->
        guess()
      yes_or_no == "n\n" ->
        IO.puts("Goodbye :)")
      true ->
        IO.puts("Invalid Response - Exiting Game")
    end
  end

end

NumberGuessingGame.guess()
