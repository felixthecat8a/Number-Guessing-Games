#using Elixir
defmodule NumberGuessingGame do
  def guess() do
    debug = false #set true for debugging
    random = Enum.random(1..100)
    if debug do
      IO.puts("Answer: #{random}")
    end
    IO.puts("Guess a number between 1 and 100.")
    {first_guess, _} = IO.gets("Guess the number: ") |> Integer.parse()
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
    {new_guess, _} = IO.gets("Try again: ") |> Integer.parse()
    a = a + 1
    guess_while(answer,new_guess,a)
  end

  def too_high(answer,a) do
    IO.puts("Your number is too high.")
    {new_guess, _} = IO.gets("Try again: ") |> Integer.parse()
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
    prompt_question = "Do you want to play again? (y/n): "
    yes_or_no = IO.gets(prompt_question) |> String.trim()
    cond do
      yes_or_no == "y" ->
        game()
      yes_or_no == "n" ->
        IO.puts("Goodbye :)")
      true ->
        IO.puts("Invalid Response - Exiting Game")
    end
  end

end

NumberGuessingGame.guess()
