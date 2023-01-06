//using Node.js
//npm install prompt-sync

const prompt = require('prompt-sync')({sigint: true});

const randomNumber = Math.floor(Math.random() * 100) + 1
console.log(`Answer: ${randomNumber}`) //for debugging

let attempts = 0
let matching = false

console.log("Guess the number between 1 and 100.")
let guess = prompt("Guess the number: ")
do {
    attempts++
    if (guess < randomNumber) {
        console.log("Your number is too low.")
        guess = prompt("Try again: ")
    } else if (guess > randomNumber) {
        console.log("Your number is too high.")
        guess = prompt("Try again: ")
    } else {
        console.log("You guessed it right!</div>")
        console.log(`It only took you ${attempts} ${tries(attempts)}.`)
        matching = true
    }
} while (!matching)

function tries(attempts) {
    if (attempts === 1) {
        return "try"
    }else{
        return "tries"
    }
}
