const check = document.getElementById("check")
const guess = document.getElementById("guess")
const result = document.getElementById("result")
const reset = document.getElementById("reset")


function playGame() {
  let randomNumber = Math.floor(Math.random() * 100) + 1
  console.log(randomNumber) //for debugging
  let attempts = 0
  check.addEventListener("click", guessNumber)
  function guessNumber() {
      attempts++
      if (guess.value < randomNumber) {
          result.innerHTML = `<div style='color:cornflowerblue'>Attempt number ${attempts} was too low. Try again.</div>`
      } else if (guess.value > randomNumber) {
          result.innerHTML = `<div style='color:palevioletred'>Attempt number ${attempts} was too high. Try again.</div>`
      } else {
          result.innerHTML = `<span style='color:gold'>You guessed it right!</span><br><br>It only took you ${attempts} ${tries()}.`
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
    reset.innerHTML = "<div id='reset'></div>" 
    playGame()
}
