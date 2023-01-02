const randomNumber = Math.floor(Math.random() * 100) + 1        
const check = document.getElementById("check")
const guess = document.getElementById("guess")
const result = document.getElementById("result")
const attempt = document.getElementById("attempt")
const reset = document.getElementById("reset")
let attempts = 0
check.addEventListener("click", guessNumber)

function guessNumber() {
    attempts++
    if (guess.value < randomNumber) {
        result.innerHTML = "<div class='low'>Your number is too low. Try again.</div>"
        attempt.innerHTML = `<h3>Attempt number ${attempts}.</h3>`
    } else if (guess.value > randomNumber) {
        result.innerHTML = "<div class='high'>Your number is too high. Try again.</div>"
        attempt.innerHTML = `<h3>Attempt number ${attempts}.</h3>`
    } else {
        result.innerHTML = "<div class='right'>You guessed it right!</div>"
        attempt.innerHTML = `<h3>It only took you ${attempts} tries.</h3>`
        reset.innerHTML = "<h3><a href=''> Click to play again.</a></h3>"
    }
}
