#using Ruby
debug = false #set true to debug
puts "Guess the number between 1 and 100."

number = rand(100)
if debug
    puts "Answer: #{number}"
end

puts "Guess the number: "
guess = gets.chomp.to_i

attempts = 1

while guess != number
    attempts +=1
    if guess < number
        puts "Your number is too low."
        puts "Try again: "
        guess = gets.chomp.to_i
    elsif guess > number
        puts "Your number is too high."
        puts "Try again: "
        guess = gets.chomp.to_i
    else
        break
    end
end

puts "You guessed it right!"

if attempts == 1
    tries = "attempt"
else
    tries = "attempts"
end

puts "It only took you #{attempts} #{tries}. :)"
