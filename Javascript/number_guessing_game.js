//using Node.js
//npm install prompt-sync

const prompt = require('prompt-sync')({sigint: true});

const randomNumber = Math.floor(Math.random() * 100) + 1
console.log(`Answer: ${randomNumber}`) //for debugging

let attempts = 1

console.log("Guess the number between 1 and 100.")
let guess = prompt("Guess the number: ")
do {
    attempts++
    if (guess < randomNumber) {
        console.log("Your number is too low.")
    } else if (guess > randomNumber) {
        console.log("Your number is too high.")
    } else {break}
    guess = prompt("Try again: ")
} while (guess != randomNumber)

console.log("You guessed it right!</div>")
console.log(`It only took you ${attempts} ${tries(attempts)}.`)
    
function tries(attempts) {
    if (attempts === 1) {
        return "try"
    }else{
        return "tries"
    }
}
