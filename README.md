# Tic-Tac-Toe Game in C++

This is a simple command-line implementation of the classic game of Tic-Tac-Toe in C++. It allows two players to take turns and keeps track of their scores. Additionally, players can choose to rematch or stop the game at any time.

## Table of Contents

- Getting Started
- How to Play
- Features
- License

## Getting Started

To run the Tic-Tac-Toe game, follow these steps:

1. Clone the repository to your local machine:

```bash
git clone <repository-url>
```

2. Compile the code using a C++ compiler (e.g., g++):

```bash
g++ -o TicTacToe main.cpp TicTacToe.cpp
```

3. Run the compiled program:

```bash
./TicTacToe
```

## How to Play

When you run the game, you will be prompted to enter the names of Player X and Player O.

The game will display an empty Tic-Tac-Toe board with positions labeled from 1 to 9. Players take turns entering their moves by specifying the row and column where they want to place their symbol ('X' for Player X and 'O' for Player O). For example, entering "1 2" will place 'X' in the top-right position.

The game will check for a win or a draw after each move. If a player wins, their name will be displayed along with the winning message. If the game ends in a draw, it will be indicated.

After each game, players have the option to rematch or stop the game.

The game keeps track of the scores for Player X and Player O.

## Features

- Two players can play against each other.
- The game displays a visually appealing Tic-Tac-Toe board.
- Players can rematch after a game ends.
- Players can choose to stop the game at any time.
- Scores for Player X and Player O are tracked.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Code Explanation

The code for the Tic-Tac-Toe game is split into three files:

- `README.md`: This file contains the documentation for the game, including instructions on how to play and the features of the game.
- `TicTacToe.cpp`: This file contains the implementation of the game logic, including the functions
