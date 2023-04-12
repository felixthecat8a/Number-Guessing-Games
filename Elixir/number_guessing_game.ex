#using Elixir
defmodule NumberGame do

  def start_game() do
    debug = false #set true for debugging
    IO.puts("Guess the number between 1 and 100.")
    min = 1
    max = 100
    answer = Enum.random(min..max)
    if debug do
      IO.puts("Answer: #{answer}")
    end
    attempts = 1
    prompt = "Guess the number: "
    game_loop(answer, attempts, prompt)
  end

  def game_loop(answer, attempts, prompt) do
    case IO.gets(prompt) |> String.trim() |> Integer.parse() do
      {number, _} when number < answer ->
        too_low(answer, attempts)
      {number, _} when number > answer ->
        too_high(answer, attempts)
      {number, _} when number == answer ->
        win(attempts)
      _ ->
        IO.puts("Invalid input. Please enter a valid number.")
        prompt = "Try again: "
        game_loop(answer, attempts, prompt)
    end
    play_again()
  end

  def too_low(answer, attempts) do
    IO.puts("Your number is too low.")
    prompt = "Try again: "
    attempts = attempts + 1
    game_loop(answer, attempts, prompt)
  end

  def too_high(answer, attempts) do
    IO.puts("Your number is too high.")
    prompt = "Try again: "
    attempts = attempts + 1
    game_loop(answer, attempts, prompt)
  end

  def win(attempts) do
    IO.puts("You guessed it right!!")
    IO.puts("It only took you #{attempts} #{tries(attempts)}. :)")
  end

  def tries(attempts) do
    case 1 do
      ^attempts -> :try
      _ -> :tries
    end
  end

  def play_again() do
    prompt_question = "\nDo you want to play again? (y/n): "
    yes_or_no = IO.gets(prompt_question) |> String.trim()
    cond do
      yes_or_no == "y" ->
        start_game()
      yes_or_no == "n" ->
        IO.puts("Goodbye :)")
        exit(:normal)
      true ->
        IO.puts("Invalid Response - Exiting Game")
        exit(:shutdown)
    end
  end
end

NumberGame.start_game()
