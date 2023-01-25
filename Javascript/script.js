const check = document.getElementById("check")
const guess = document.getElementById("guess")
const result = document.getElementById("result")
const attempt = document.getElementById("attempt")
const reset = document.getElementById("reset")


function playGame() {
  let randomNumber = Math.floor(Math.random() * 100) + 1
  console.log(randomNumber) //for debugging
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
          attempt.innerHTML = `<h3>It only took ${attempts} ${attemptsMessage()}.</h3>`
          reset.innerHTML = "<button type='reset' onclick='resetGame()'>Play Again?</button>" 
      }
  }

  function attemptsMessage() {
    if (attempts === 1) {
      return "try"
    } else {
      return "tries"
    }
  }
}
playGame()

function resetGame() {
    result.innerHTML = "<h3 id='result'>Guess the number.</h3>"
    attempt.innerHTML = "<div id='attempt'></div>"
    reset.innerHTML = "<div id='reset'></div>" 
    playGame()
}
