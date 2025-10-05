#include "TicTacToe.hpp"

TicTacToe::TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

void TicTacToe::printBoard() const
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {

            std::cout << board[i][j];
            if (j < 2)
            {
                std::cout << " | ";
            }
        }
        std::cout << "\n";
        if (i < 2)
            std::cout << "---------\n";
    }
    std::cout << "\n";
}

bool TicTacToe::isValidMove(int row, int col) const
{
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TicTacToe::Move(int row, int col)
{
    if (isValidMove(row, col) == true)
    {
        board[row][col] = currentPlayer;
        return true;
    }
    else
    {
        return false;
    }
}

void TicTacToe::switchPlayer()
{
    if (currentPlayer == 'X')
    {
        currentPlayer = 'O';
    }
    else
    {
        currentPlayer = 'X';
    }
}

char TicTacToe::checkWinner() const
{
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }
    return ' ';
}

bool TicTacToe::isBoardFull() const
{
    for (const auto &row : board)
    {
        for (char cell : row)
        {
            if (cell == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

char TicTacToe::getCurrentPlayer() const
{
    return currentPlayer;
}