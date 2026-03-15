#include "tictactoe.hpp"
#include <iostream>

    TicTacToe::TicTacToe() {
        char num = '1';
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                board[x][y] = num++;
            }
        }
    }
    void TicTacToe::draw() const {
        for (int x = 0; x < 3; x++) {
            std::cout << " " << board[x][0] << " | " << board[x][1] << " | " << board[x][2] << std::endl;

            if (x < 2)
                std::cout << "---+---+---" << std::endl;
        }
    }
    bool TicTacToe::makeMove(const int position, const char playerMark) {
        if (position < 1 || position > 9)
            return false;
        int boardNumber = 1;

        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (boardNumber == position) {
                    if (board[x][y] == 'X' || board[x][y] == 'O') {
                        return false;
                    }
                    board[x][y] = playerMark;
                }
                boardNumber++;
            }
        }


        return true;
    }
    bool TicTacToe::checkWin(char mark) const {
        for (int x = 0; x < 3; x++) {
            if (board[x][0] == mark && board[x][1] == mark && board[x][2] == mark) {
                return true;
            }
        }
        for (int y = 0; y < 3; y++) {
            if (board[0][y] == mark && board[1][y] == mark && board[2][y] == mark) {
                return true;
            }
        }
        if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) {
            return true;
        }
        if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) {
            return true;
        }
        return false;
    }
    bool TicTacToe::checkDraw() const {
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (board[x][y] != 'X' && board[x][y] != 'O') {
                    return false;
                }
            }
        }
        return true;
    }
    char TicTacToe::get(const int x, const int y) const {
        return board[x][y];
    }
