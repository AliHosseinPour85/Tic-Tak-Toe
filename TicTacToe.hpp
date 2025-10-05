#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <vector>
#include <iostream>

class TicTacToe
{
private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

public:
    TicTacToe();
    void printBoard() const;
    bool isValidMove(int row, int col) const;
    bool Move(int row, int col);
    void switchPlayer();
    char checkWinner() const;
    bool isBoardFull() const;
    char getCurrentPlayer() const;
};

#endif