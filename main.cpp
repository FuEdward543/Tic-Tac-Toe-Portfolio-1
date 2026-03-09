#include <iostream>

#include "src/tictactoe.cpp"

int main() {
  TicTacToe board;

  board.draw();
  std::cout << std::endl;

  board.makeMove(1, 'X');
  board.makeMove(5, 'O');
  board.makeMove(7, 'X');
  board.makeMove(7, 'O');

  board.draw();
}
