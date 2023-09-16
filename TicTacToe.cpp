#include "TicTacToe.hpp"
#include <iostream>

using namespace std;

TicTacToe::TicTacToe() {
    // Initialize the board and current player
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';

    // Get player names
    cout << "Enter Player X's name: ";
    cin >> playerXName;
    cout << "Enter Player O's name: ";
    cin >> playerOName;

    // Initialize scores
    playerXScore = 0;
    playerOScore = 0;
}


void TicTacToe::displayBoard() {
    cout << "\n   1   2   3" << endl;
    cout << "  -------------" << endl;

    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " | ";
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') {
                cout << "X";
            } else if (board[i][j] == 'O') {
                cout << "O";
            } else {
                cout << " ";
            }

            if (j < 2) {
                cout << " | ";
            }
        }
        cout << " |" << endl;

        if (i < 2) {
            cout << "  -------------" << endl;
        }
    }
    cout << endl;
}


bool TicTacToe::checkWin(char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Column win
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Diagonal win (top-left to bottom-right)
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Diagonal win (top-right to bottom-left)
    }
    return false;
}

bool TicTacToe::checkDraw() {
    // Check if the game is a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool TicTacToe::isValidMove(int row, int col) {
    // Check if the move is valid
    return (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ');
}

void TicTacToe::play() {
    int row, col;
    bool stopGame = false;

    cout << "Tic-Tac-Toe Game" << endl;

    while (!stopGame) {
        for (int move = 1; move <= 9; move++) {
            displayBoard();

            string playerName = (currentPlayer == 'X') ? playerXName : playerOName;
            cout << playerName << ", enter row and column (e.g., 1 2): ";
            cin >> row >> col;

            if (!isValidMove(row, col)) {
                cout << "Invalid move. Try again." << endl;
                move--;
                continue;
            }

            board[row - 1][col - 1] = currentPlayer;

            if (checkWin(currentPlayer)) {
                displayBoard();
                cout << playerName << " wins!" << endl;

                // Update scores
                if (currentPlayer == 'X') {
                    playerXScore++;
                } else {
                    playerOScore++;
                }

                // Ask for a rematch
                cout << "Rematch? (y/n): ";
                char rematchChoice;
                cin >> rematchChoice;
                if (rematchChoice == 'y' || rematchChoice == 'Y') {
                    rematch();
                } else {
                    displayScores();
                    stopGame = askToStop();
                    if (stopGame) {
                        return;
                    }
                }
            }

            if (move == 9) {
                displayBoard();
                cout << "It's a draw!" << endl;

                // Ask for a rematch
                cout << "Rematch? (y/n): ";
                char rematchChoice;
                cin >> rematchChoice;
                if (rematchChoice == 'y' || rematchChoice == 'Y') {
                    rematch();
                } else {
                    displayScores();
                    stopGame = askToStop();
                    if (stopGame) {
                        return;
                    }
                }
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}


void TicTacToe::rematch() {
    // Reset the board for a rematch
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';
}

void TicTacToe::displayScores() {
    cout << "Scores:" << endl;
    cout << playerXName << ": " << playerXScore << endl;
    cout << playerOName << ": " << playerOScore << endl;
}


bool TicTacToe::askToStop() {
    char choice;
    cout << "Do you want to stop the game? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
