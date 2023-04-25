#include <iostream>
#include <vector>
#include <cmath>

class Move
{
public:
    Move(int p, int s)
    {
        pos = p;
        side = s;
    }
    int pos;
    int side;
};

class Board
{
public:
    int board[9];
    int turn;
    std::vector<Move> history;
    Board()
    {
        for (int i = 0; i < 9; i++)
        {
            board[i] = 0;
        }
        turn = 1;
    }

    void displayBoard()
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i] == 1)
            {
                std::cout << 'O';
            }
            if (board[i] == 2)
            {
                std::cout << 'X';
            }
            if (board[i] == 0)
            {
                std::cout << '#';
            }
            if (i % 3 == 2)
            {
                std::cout << '\n';
            }
        }
    }

    // returns int based on state of game
    // one is O wins
    // two is X wins
    // zero is not over
    int winState()
    {
        // row
        if ((board[0] == board[3] && board[6] == board[3]))
        {
            return board[0];
        }
        if ((board[1] == board[4] && board[7] == board[4]))
        {
            return board[1];
        }
        if ((board[2] == board[5] && board[8] == board[5]))
        {
            return board[2];
        }
        // col
        if ((board[0] == board[1] && board[2] == board[1]))
        {
            return board[0];
        }
        if ((board[3] == board[4] && board[5] == board[4]))
        {
            return board[3];
        }
        if ((board[6] == board[7] && board[8] == board[7]))
        {
            return board[6];
        }
        // diag
        if ((board[0] == board[4] && board[8] == board[4]) ||
            (board[2] == board[4] && board[6] == board[4]))
        {
            return board[4];
        }
        return 0;
    }

    // isboardfull
    bool isBoardFull()
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i] == 0)
            {
                return false;
            }
        }
        return true;
    }

    // getMoves
    std::vector<Move> getMoves()
    {
        std::vector<Move> moves;
        for (int i = 0; i < 9; i++)
        {
            if (board[i] == 0)
            {
                moves.push_back(Move(i, turn));
            }
        }
        return moves;
    }

    // makemove
    void makeMove(Move toMake)
    {
        history.push_back(toMake);
        board[toMake.pos] = toMake.side;
        turn = (turn == 1) ? 2 : 1;
    }

    // unmakemove
    void unmakeMove()
    {
        turn = (turn == 1) ? 2 : 1;
        board[history.back().pos] = 0;
        history.pop_back();
    }
};

// eval
int evalFunction(Board board)
{
    if (board.winState() == 1)
    {
        return 1;
    }
    else if (board.winState() == 2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

// minimaxRoot
int minimaxRoot(Board board, int depth)
{
    std::vector<Move> moves = board.getMoves();
    int bestMove = 0;
    int bestMoveValue = 0;
    int value = 0;

    if (board.turn == 1) // Max player
    {
        bestMove = -1;
        bestMoveValue = -999999;
        for (int i = 0; i < moves.size(); i++)
        {
            board.makeMove(moves[i]);
            value = minimax(board, depth - 1);
            board.unmakeMove();
            if (value > bestMoveValue)
            {
                bestMove = i;
                bestMoveValue = value;
            }
        }
        return bestMove;
    }
    else // min player
    {
        bestMove = -1;
        bestMoveValue = 999999;
        for (int i = 0; i < moves.size(); i++)
        {
            board.makeMove(moves[i]);
            value = minimax(board, depth - 1);
            board.unmakeMove();
            if (value < bestMoveValue)
            {
                bestMove = i;
                bestMoveValue = value;
            }
        }
        return bestMove;
    }
}

// minimax
int minimax(Board board, int depth)
{
    std::vector<Move> moves = board.getMoves();
    int bestMove = 0;
    int bestMoveValue = 0;
    int value = 0;

    if (board.turn == 1) // Max player
    {
        bestMoveValue = -999999;
        for (int i = 0; i < moves.size(); i++)
        {
            board.makeMove(moves[i]);
            value = minimax(board, depth - 1);
            board.unmakeMove();
            bestMoveValue = std::max(value, bestMoveValue);
        }
        return bestMove;
    }
    else // min player
    {
        bestMoveValue = 999999;
        for (int i = 0; i < moves.size(); i++)
        {
            board.makeMove(moves[i]);
            value = minimax(board, depth - 1);
            board.unmakeMove();
            bestMoveValue = std::min(value, bestMoveValue);
        }
        return bestMove;
    }
}

int main()
{
    Board game;

    game.displayBoard();
}