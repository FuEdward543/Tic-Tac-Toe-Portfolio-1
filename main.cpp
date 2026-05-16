#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
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

int getIntInput() {
    int input;
    while (true) {
        cin >> input;
        if (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }
        if (cin.peek() != '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a single number." << endl;
            continue;
        }
        break;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
}

char getCharInput() {
    char input;
    while (true) {
        cin >> input;
        if (!cin.good()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a character." << endl;
            continue;
        }
        if (cin.peek() != '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a single character." << endl;
            continue;
        }
        break;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
}

int main() {
    srand(time(nullptr));
    bool replay = true;

    while (replay) {
        cout << "Welcome to Tic-Tac-Toe!" << endl;
        cout << "1. Play vs Human" << endl;
        cout << "2. Play vs Computer" << endl;
        cout << "Choose an option: ";

        int mode = getIntInput();

        bool vsComputer = false;
        bool computerFirst = false;

        if (mode == 2) {
            vsComputer = true;
            while (true) {
                cout << "Should the computer go first? (Y/N)";
                char choice = getCharInput();
                if (choice == 'Y' || choice == 'y') {
                    computerFirst = true;
                    break;
                } else if (choice == 'N' || choice == 'n') {
                    break;
                } else {
                    cout << "Invalid input. Please enter Y or N" << endl;
                }
            }
        } else if (mode != 1) {
            cout << "Invalid input: Please enter 1 or 2" << endl;
            continue;
        }

        TicTacToe board;

        cout << "Enable trap cell? (Y/N): ";
        char trapChoice = getCharInput();
        if (trapChoice == 'Y' || trapChoice == 'y') {
            board.enableTrap();
            cout << "A trap cell has been hidden on the board..." << endl;
        }

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
                position = getIntInput();
                if (!board.makeMove(position, currentPlayer)) {
                    cout << "Invalid move. Try again." << endl;
                    continue;
                }
            }

            if (board.checkWin(currentPlayer)) {
                board.draw();
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameOver = true;
            } else if (board.checkDraw()) {
                board.draw();
                cout << "It's a draw!" << endl;
                gameOver = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

        while (true) {
            cout << "Would you like to play again? (Y/N)";
            char choice = getCharInput();
            if (choice == 'y' || choice == 'Y') {
                replay = true;
                cout << "Starting a new game" << endl;
                break;
            } else if (choice == 'n' || choice == 'N') {
                replay = false;
                cout << "Ending game" << endl;
                break;
            } else {
                cout << "Invalid input. Please enter Y or N" << endl;
            }
        }
    }
}
