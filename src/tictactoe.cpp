#include <iostream>
#include <string>


class TicTacToe {
private:
    char board[3][3]{};

public:
    TicTacToe() {
        char num = '1';
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                board[x][y] = num++;
            }
        }
    }

    void draw() const {
        for (int x = 0; x < 3; x++) {
            std::cout << " " << board[x][0] << " | " << board[x][1] << " | " << board[x][2] << std::endl;

            if (x < 2)
                std::cout << "---+---+---" << std::endl;
        }
    }

    bool makeMove(const int position, const char playerMark) {
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
};
