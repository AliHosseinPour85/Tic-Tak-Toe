#include "TicTacToe.hpp"

int main()
{
    TicTacToe game;
    int row, col;
    char winner = ' ';

    std::cout << "Welcome to the Tic Tac Toe game!!\n-Player one : X\n-Player two : O\n";

    while (winner == ' ' && game.isBoardFull() == false)
    {
        std::cout << "--------------------------" << std::endl;
        std::cout << "Player " << game.getCurrentPlayer() << " enter your move : ";
        std::cin >> row >> col;

        if (game.Move(row, col))
        {
            winner = game.checkWinner();
            if (winner == ' ')
            {
                game.switchPlayer();
            }
            game.printBoard();
        }
        else
        {
            std::cout << "Invalide move . Please try again!!\n";
        }
    }

    if (winner == 'X')
    {
        std::cout << "Player ONE Win !\n";
    }
    else if (winner == 'O')
    {
        std::cout << "Player TWO Win !\n";
    }
    else
    {
        std::cout << "DRAW\n";
    }

    return 0;
}