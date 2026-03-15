#include <iostream>
#include "src/tictactoe.hpp"
using namespace std;

int main() {
    bool replay = true;
    while (replay) {

        TicTacToe board;
        char currentPlayer = 'X';
        bool gameOver = false;

        while (!gameOver) {
            board.draw();
            cout << "Player " << currentPlayer << ", enter a number from 1-9: ";

            int position;
            cin >> position;

            if (!cin.good()) {
                cin.clear();
                cin.ignore();
                cout << "Invalid input. Try again." << endl;
                continue;
            }
            if (!board.makeMove(position, currentPlayer)) {
                cout << "Invalid move. Try again." << endl;
                continue;
            }
            if (board.checkWin(currentPlayer)) {
                board.draw();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            }
            else if (board.checkDraw()) {
                board.draw();
                cout << "It's a draw!" << endl;
                gameOver = true;
            }
            else {
                if (currentPlayer == 'X') {
                    currentPlayer = 'O';
                } else {
                    currentPlayer = 'X';
                }
            }
        }
        cout << "Play again? Y or N: ";
        char choice;
        cin.ignore();
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            replay = true;
            cout << "Starting a new game" << endl;
        } else {
            replay = false;
            cout << "Ending game" << endl;
        }
    }
}