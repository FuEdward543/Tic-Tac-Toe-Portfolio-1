class TicTacToe {
private:
    char board[3][3];
    int trapPosition;
    bool trapEnabled;

public:
    TicTacToe();

    void enableTrap();
    bool isTrap(int position) const;

    void draw() const;
    bool makeMove(int position, char playerMark);
    bool checkWin(char mark) const;
    bool checkDraw() const;
    char get(int x, int y) const;
};
