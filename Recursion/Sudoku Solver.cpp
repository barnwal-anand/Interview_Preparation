/*
Leetcode: 37. Sudoku Solver
Input: board = [["5","3",".",".","7",".",".",".","."],
                ["6",".",".","1","9","5",".",".","."],
                [".","9","8",".",".",".",".","6","."],
                ["8",".",".",".","6",".",".",".","3"],
                ["4",".",".","8",".","3",".",".","1"],
                ["7",".",".",".","2",".",".",".","6"],
                [".","6",".",".",".",".","2","8","."],
                [".",".",".","4","1","9",".",".","5"],
                [".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],
         ["6","7","2","1","9","5","3","4","8"],
         ["1","9","8","3","4","2","5","6","7"],
         ["8","5","9","7","6","1","4","2","3"],
         ["4","2","6","8","5","3","7","9","1"],
         ["7","1","3","9","2","4","8","5","6"],
         ["9","6","1","5","3","7","2","8","4"],
         ["2","8","7","4","1","9","6","3","5"],
         ["3","4","5","2","8","6","1","7","9"]]
*/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();

        solveSudokuUtil(board, 0, n);
        return;
    }

    bool solveSudokuUtil(vector<vector<char>>& board, int index, int n) {
        if (index == n*n) {
            return true;
        }

        int r = index / n;
        int c = index % n;

        if (board[r][c] != '.') {
            return solveSudokuUtil(board, index+1, n);
        }

        for (int num = 1; num <= n; num++) {
            if (isSafe(board, n, r, c, num)) {
                board[r][c] = num+'0';
                if(solveSudokuUtil(board, index+1, n)) {
                    return true;
                }
            }
        }

        board[r][c] = '.';
        return false;
    }

    bool isSafe(vector<vector<char>>& board, int size, int r, int c, int num) {
        for(int it = 0; it < size; it++) {
            if(board[it][c] == num+'0' || board[r][it] == num+'0')
                return false;
        }

        int sx = (r / 3) * 3;
        int sy = (c / 3) * 3;
        for(int x = sx; x < sx + 3; x++) {
            for(int y = sy; y < sy + 3; y++) {
                if(board[x][y] == num+'0')
                    return false;
            }
        }

        return true;
    }
};
