const languagePairs = [];
for (const [fromLang, toLangs] of Object.entries(dicts)) {
  for (const [toLang, words] of Object.entries(toLangs)) {
    languagePairs.push({ fromLang, toLang, words });
  }
}

const wordFromLabel = document.querySelector("#wordFrom");
const wordToInput = document.querySelector("#wordTo");
const seeAnswerButton = document.querySelector("#seeAnswer");
const wordsDatalist = document.querySelector("#words");
const languageFromLabels = document.querySelectorAll(".languageFrom");
const languageToLabels = document.querySelectorAll(".languageTo");
const cols = document.querySelectorAll(".col");

let currentPair;
let currentWord;

function pickRandom(arr) {
  return arr[Math.floor(Math.random() * arr.length)];
}

function resetChallenge() {
  currentPair = pickRandom(languagePairs);
  const [from, to] = pickRandom(Object.entries(currentPair.words));
  currentWord = { from, to };

  languageFromLabels.forEach((el) => (el.textContent = currentPair.fromLang));
  languageToLabels.forEach((el) => (el.textContent = currentPair.toLang));
  wordFromLabel.textContent = from;

  wordsDatalist.innerHTML = "";
  for (const word of Object.values(currentPair.words)) {
    const option = document.createElement("option");
    option.value = word;
    wordsDatalist.appendChild(option);
  }
}

function submitAnswer() {
  if (wordToInput.value.trim().length === 0) return;
  appendHistory(currentWord, wordToInput.value);
  wordToInput.value = "";
  wordToInput.setAttribute("list", "");
  resetChallenge();
}

function appendHistory(word, guess) {
  const isCorrect = word.to === guess;

  const fromSpan = document.createElement("span");
  fromSpan.textContent = word.from;
  fromSpan.classList.add(isCorrect ? "correct" : "incorrect");
  cols[0].insertBefore(fromSpan, cols[0].children[2] ?? null);

  const guessSpan = document.createElement("span");
  guessSpan.textContent = guess;
  guessSpan.classList.add(isCorrect ? "correct" : "incorrect");
  if (!isCorrect) guessSpan.classList.add("strike");
  cols[1].insertBefore(guessSpan, cols[1].children[2] || null);

  const answerSpan = document.createElement("span");
  answerSpan.textContent = isCorrect ? "✔️" : word.to;
  answerSpan.classList.add(isCorrect ? "icon" : "incorrect");
  cols[2].insertBefore(answerSpan, cols[2].children[2] || null);
}

resetChallenge();

seeAnswerButton.addEventListener("click", submitAnswer);

wordToInput.addEventListener("input", (e) => {
  if (e.inputType === "insertReplacementText" || e.inputType === undefined) {
    submitAnswer();
    return;
  }
  const showSuggestions = wordToInput.value.length >= 2;
  wordToInput.setAttribute("list", showSuggestions ? "words" : "");
});

wordToInput.addEventListener("keydown", (e) => {
  if (e.key === "Enter") submitAnswer();
});
