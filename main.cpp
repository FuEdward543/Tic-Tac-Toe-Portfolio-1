#include <iostream>
#include <limits>
#include "src/tictactoe.hpp"
using namespace std;

int getComputerMove(const TicTacToe& board) {
    for (int pos = 1; pos <= 9; pos++) {
        int x = (pos - 1) / 3;
        int y = (pos - 1) % 3;
        char cell = board.get(x, y);
        if (cell != 'X' && cell != 'O') {
            return pos;
        }
    }
    return -1;
}

int main() {
    bool replay = true;

    while (replay) {
        cout << "Welcome to Tic-Tac-Toe!" << endl;
        cout << "1. Play vs Human" << endl;
        cout << "2. Play vs Computer" << endl;
        cout << "Choose an option: ";

        int mode;
        cin >> mode;

        bool vsComputer = false;
        bool computerFirst = false;

        if (mode == 2) {
            vsComputer = true;
            cout << "Should the computer go first? (Y/N): ";
            char choice;
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                computerFirst = true;
            }
        }

        TicTacToe board;
        char currentPlayer = 'X';
        bool gameOver = false;

        if (vsComputer && computerFirst) {
            int move = getComputerMove(board);
            board.makeMove(move, 'O');
            currentPlayer = 'X';
        }

        while (!gameOver) {
            board.draw();
            int position;

            if (vsComputer && currentPlayer == 'O') {
                int move = getComputerMove(board);
                board.makeMove(move, 'O');
                cout << "Computer chose position " << move << endl;
            } else {
                cout << "Player " << currentPlayer << ", enter a number from 1-9: ";
                cin >> position;

                if (!cin.good()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Try again." << endl;
                    continue;
                }
                if (!board.makeMove(position, currentPlayer)) {
                    cout << "Invalid move. Try again." << endl;
                    continue;
                }
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