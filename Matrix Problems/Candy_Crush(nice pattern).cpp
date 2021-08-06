// LeetCode - 723. Candy Crush

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        if (board.size() == 0)
            return board;

        int R = board.size();
        int C = board[0].size();

        while(CanBeCrushed(board, R, C))
        {
            drop(board, R, C);
        }

        return board;
    }

    bool CanBeCrushed(vector<vector<int>>& board, const int &R, const int &C)
    {
        bool crushH = crushHorizontally(board, R, C);
        bool crushV = crushVertically(board, R, C);

        return crushH || crushV;
    }

    bool crushHorizontally(vector<vector<int>>& board, const int &R, const int &C)
    {
        bool flag = false;

        for (int r = 0; r < R; r++)
        {
            for (int c = 0; c < C - 2; c++)
            {
                if (board[r][c] != 0 &&
                    abs(board[r][c]) == abs(board[r][c + 1]) &&
                    abs(board[r][c]) == abs(board[r][c + 2]))
                {
                    board[r][c] = -abs(board[r][c]);
                    board[r][c + 1] = -abs(board[r][c]);
                    board[r][c + 2] = -abs(board[r][c]);
                    flag = true;
                }
            }
        }

        return flag;
    }

    bool crushVertically(vector<vector<int>>& board, const int &R, const int &C)
    {
        bool flag = false;
        for (int r = 0; r < R - 2; r++)
        {
            for (int c = 0; c < C; c++)
            {
                if (board[r][c] != 0 &&
                    abs(board[r][c]) == abs(board[r + 1][c]) &&
                    abs(board[r][c]) == abs(board[r + 2][c]))
                {
                    board[r][c] = -abs(board[r][c]);
                    board[r + 1][c] = -abs(board[r][c]);
                    board[r + 2][c] = -abs(board[r][c]);
                    flag = true;
                }
            }
        }

        return flag;
    }

    void drop(vector<vector<int>>& board, const int &R, const int &C)
    {
        replaceNegative(board, R, C);

        for (int c = 0; c < C; c++)
        {
            int depth = R - 1;
            for (int r = R - 1; r >=0; r--)
            {
                if (board[r][c] != 0)
                    board[depth--][c] = board[r][c];
            }
            for (int r = depth; r >= 0; r--)
            {
                board[r][c] = 0;
            }
        }
    }

    void replaceNegative(vector<vector<int>>& board, const int &R, const int &C)
    {
        for (int r = 0; r < R; r++)
        {
            for (int c = 0; c < C; c++)
            {
                if (board[r][c] < 0)
                    board[r][c] = 0;
            }
        }
    }
};
