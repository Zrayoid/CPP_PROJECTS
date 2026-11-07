# 🎯 Number Guessing Game

A simple C++ console-based number guessing game where the player tries to guess a randomly generated number between **1 and 100**.

The game provides hints after every incorrect guess, helping the player get closer to the correct number.

## 🎮 How to Play

1. The computer generates a random number between 1 and 100.
2. Enter your guess.
3. The game tells you whether your guess is too high or too low.
4. It also provides hints based on how far your guess is from the secret number.
5. Keep guessing until you find the correct number.
6. Choose whether you want to play another round.

## ✨ Features

- Random number generation using C++ `<random>`.
- Input validation to prevent guesses outside the 1–100 range.
- Handles invalid non-integer input.
- Distance-based hints:
  - **20 or more away:** Too high / Too low.
  - **10–19 away:** High / Low.
  - **5–9 away:** Close.
  - **1–4 away:** Very close.
- Multiple rounds of gameplay.

## 🛠️ Concepts Used

- C++ functions
- `while` loops
- Conditional statements (`if`, `else if`, `else`)
- Boolean return values
- User input and output (`cin`, `cout`)
- Input validation using `cin.clear()` and `cin.ignore()`
- Random number generation:
  - `random_device`
  - `mt19937`
  - `uniform_int_distribution`

## ▶️ How to Run

**1. Clone the repository**

```bash
git clone <repository-url>
```

**2. Navigate to the project folder**

```bash
cd "Number Guessing Game"
```

**3. Compile the program**

```bash
g++ main.cpp -o guessing_game
```

**4. Run the game**

```bash
./guessing_game
```

On Windows:

```bash
guessing_game.exe
```

## 📚 What I Learned

This project helped me practise combining functions, loops, conditions, input validation, and random number generation into one interactive program.

It was also an opportunity to work with the modern C++ `<random>` library instead of relying on the older `rand()` approach.

---

**Project Level:** 1 – Beginner  
**Language:** C++  
**Type:** Console Application  
**Status:** Completed
