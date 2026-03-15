#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/tictactoe.hpp"

TEST_CASE( "board is made properly" ) {
    TicTacToe board;
    REQUIRE(board.get(0,0) == '1');
    REQUIRE(board.get(0,1) == '2');
    REQUIRE(board.get(0,2) == '3');
    REQUIRE(board.get(1,0) == '4');
    REQUIRE(board.get(1,1) == '5');
    REQUIRE(board.get(1,2) == '6');
    REQUIRE(board.get(2,0) == '7');
    REQUIRE(board.get(2,1) == '8');
    REQUIRE(board.get(2,2) == '9');
}
TEST_CASE("X and O can be placed") {
    TicTacToe board;

    REQUIRE(board.makeMove(1, 'X') == true);
    REQUIRE(board.get(0,0) == 'X');

    REQUIRE(board.makeMove(2, 'O') == true);
    REQUIRE(board.get(0,1) == 'O');
}
TEST_CASE("X and O can not be placed on the same spot") {
    TicTacToe board;

    REQUIRE(board.makeMove(1, 'X') == true);
    REQUIRE(board.makeMove(1, 'O') == false);
}
TEST_CASE("checkWin works") {
    TicTacToe board;

    board.makeMove(1, 'X');
    board.makeMove(2, 'X');
    board.makeMove(3, 'X');

    REQUIRE(board.checkWin('X') == true);
}
TEST_CASE("checkDraw works") {
    TicTacToe board;

    board.makeMove(1, 'X');
    board.makeMove(2, 'O');
    board.makeMove(3, 'O');
    board.makeMove(4, 'O');
    board.makeMove(5, 'X');
    board.makeMove(6, 'X');
    board.makeMove(7, 'X');
    board.makeMove(8, 'X');
    board.makeMove(9, 'O');

    REQUIRE(board.checkWin('X') == false);
    REQUIRE(board.checkWin('O') == false);
    REQUIRE(board.checkDraw() == true);
}
