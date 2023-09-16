#ifndef TICTACTOE_H
#define TICTACTOE_H
#include <iostream>

using namespace std;
class TicTacToe {
public:
    TicTacToe();
    void play();
    void rematch();
    void displayScores();
    bool askToStop();

private:
    char board[3][3];
    char currentPlayer;
    std::string playerXName;
    std::string playerOName;
    int playerXScore;
    int playerOScore;

    void displayBoard();
    bool checkWin(char player);
    bool checkDraw();
    bool isValidMove(int row, int col);
};

#endif
