#using Ruby
debug = false #set true to debug
puts "Guess the number between 1 and 100."

number = rand(100)
if debug
    puts "Answer: #{number}"
end

print "Guess the number: "
guess = gets.chomp.to_i

attempts = 1

while guess != number
    attempts +=1
    if guess < number
        puts "Your number is too low."
        print "Try again: "
        guess = gets.chomp.to_i
    elsif guess > number
        puts "Your number is too high."
        print "Try again: "
        guess = gets.chomp.to_i
    end
end

puts "You guessed it right!"

tries = attempts == 1 ?  "attempt" : "attempts"

puts "It only took you #{attempts} #{tries}. :)"
