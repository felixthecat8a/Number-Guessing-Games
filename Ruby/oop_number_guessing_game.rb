#using Ruby
class NumberGuessingGame

  def initialize(debug)
    @debug = debug 
  end

  def game
    puts "Guess the number between 1 and 100."
    number = rand(100)
    if @debug
        puts "Answer: #{number}"
    end
    print "Guess the number: "
    @guess = gets.chomp.to_i
    @attempts = 1
    while @guess != number
        @attempts +=1
        if @guess < number
            too_low()
        elsif @guess > number
            too_high()
        end
    end
    win()
  end

  def too_low
    puts "Your number is too low."
    print "Try again: "
    @guess = gets.chomp.to_i
  end

  def too_high
    puts "Your number is too high."
    print "Try again: "
    @guess = gets.chomp.to_i
  end

  def win
    puts "You guessed it right!"
    if @attempts == 1
        tries = "attempt"
    else
        tries = "attempts"
    end
    puts "It only took you #{@attempts} #{tries}. :)"
    play_again()
  end

  def play_again()
    print "Do you want to play again? (y/n): "
    yes_or_no = gets.chomp.downcase
    case yes_or_no
    when "y"
      game()
    when "n"
      puts "Goodbye :)"
    else
      puts "Invalid Response - Exiting Game"
    end
  end
end

play = NumberGuessingGame.new(debug=false) #set true to debug
play.game() 
