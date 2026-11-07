# 🎮 Tic-Tac-Toe (C++)

A simple two-player Tic-Tac-Toe game built using C++.

## 📌 Game Overview

Tic-Tac-Toe is a two-player game played on a 3×3 grid. Players take turns marking empty positions on the board. The first player to align three of their marks wins.

## 🎯 Rules

1. The game is played by two players: **X** and **O**.
2. Player X always takes the first turn.
3. Players take turns choosing a position from **1 to 9**.
4. Each position can only be selected once.
5. A player wins by placing three of their marks in:
   - A horizontal row
   - A vertical column
   - Either diagonal
6. If all nine positions are filled and neither player wins, the game ends in a draw.

## 🕹️ Board Layout

At the beginning, the board looks like this:

```text
1  2  3
4  5  6
7  8  9
```

Enter the number corresponding to the position where you want to place your mark.

## 🏆 Winning Examples

**Horizontal win**
```text
X  X  X
4  O  6
O  8  9
```

**Vertical win**
```text
X  2  O
X  O  6
X  8  9
```

**Diagonal win**
```text
X  2  O
4  X  6
O  8  X
```

## ⚠️ Input Rules

- Only numbers from **1 to 9** are accepted.
- Letters and other non-numeric inputs are rejected.
- Positions already occupied by X or O cannot be selected.
- Invalid moves do not consume a turn.

## 🛠️ Technologies

- C++
- Standard Input/Output (`iostream`)
- 2D Character Arrays
- Functions and Pointers
- Loops and Conditional Statements

## 🚀 Current Features

- Two-player gameplay
- Interactive 3×3 board
- Automatic turn switching
- Input validation
- Prevention of occupied-position selection
- Horizontal, vertical, and diagonal win detection
- Draw detection

## 🔮 Future Improvements

- Code refactoring and cleanup
- Improved input handling
- Option to restart the game
- Better board formatting

---

*Built as part of my C++ programming journey.*
