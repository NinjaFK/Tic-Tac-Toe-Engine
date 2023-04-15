#include <iostream>

class TicTacToe
{

public:
    void displayBoard()
    {
    }

    // returns int based on state of game
    // one is O wins
    // two is X wins
    // zero is not over
    int winState()
    {
        // O
        // row
        if ((board[0] == 1 && board[3] == 1 && board[6] == 1) ||
            (board[1] == 1 && board[4] == 1 && board[7] == 1) ||
            (board[2] == 1 && board[5] == 1 && board[8] == 1))
        {
            return 1;
        }
        // col
        if ((board[0] == 1 && board[1] == 1 && board[2] == 1) ||
            (board[3] == 1 && board[4] == 1 && board[5] == 1) ||
            (board[6] == 1 && board[7] == 1 && board[8] == 1))
        {
            return 1;
        }
        // diag
        if ((board[0] == 1 && board[4] == 1 && board[8] == 1) ||
            (board[2] == 1 && board[4] == 1 && board[6] == 1))
        {
            return 1;
        }
        // X
        // row
        if ((board[0] == 2 && board[3] == 2 && board[6] == 2) ||
            (board[1] == 2 && board[4] == 2 && board[7] == 2) ||
            (board[2] == 2 && board[5] == 2 && board[8] == 2))
        {
            return 2;
        }
        // col
        if ((board[0] == 2 && board[1] == 2 && board[2] == 2) ||
            (board[3] == 2 && board[4] == 2 && board[5] == 2) ||
            (board[6] == 2 && board[7] == 2 && board[8] == 2))
        {
            return 2;
        }
        // diag
        if ((board[0] == 2 && board[4] == 2 && board[8] == 2) ||
            (board[2] == 2 && board[4] == 2 && board[6] == 2))
        {
            return 2;
        }
        return 0;
    }

    // mini max

private:
    int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
};

int main()
{
}