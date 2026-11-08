# Tic-Tac-Toe – C++

A two-player Tic-Tac-Toe game built using C++. Players take turns placing **X** and **O** on a 3×3 board. The first player to align three identical symbols horizontally, vertically, or diagonally wins. If all nine positions are filled without a winner, the game ends in a draw.

## Previous Version

The initial version used separate functions for displaying the board, validating input, checking winners, managing turns, and placing symbols. It worked, but some logic was repetitive, the board display was basic, and input validation needed improvement.

## Improvements

- **Input validation:** Reworked validation using `getline()`, `stringstream`, and stream checks to validate the entire input line. Rejects invalid formats, extra characters, decimals, and out-of-range positions.
- **Win detection:** Simplified winner checking by directly comparing rows, columns, and diagonals instead of maintaining multiple counters.
- **Game logic:** Removed duplicated X/O placement code using the conditional operator and `continue`.
- **Board display:** Added cleaner spacing and grid separators.
- **Turn display:** Simplified player selection using the conditional operator.

## What I Learned

- Passing arrays to functions using pointers.
- Working with pointers and dereferencing.
- Input streams, `getline()`, and `stringstream`.
- Validating complete user input.
- Using `continue` to control loops.
- Simplifying conditional logic.
- Checking winning combinations in a 2D array.
- Writing reusable functions and reducing code duplication.

**Main takeaway:** Improving a working program is just as important as building it. This project helped me understand defensive programming, cleaner logic, and better input handling.
