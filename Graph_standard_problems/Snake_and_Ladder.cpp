/*
Leetcode: 909 Snakes and Ladders
Input: board = [[-1,-1,-1,-1,-1,-1],
                [-1,-1,-1,-1,-1,-1],
                [-1,-1,-1,-1,-1,-1],
                [-1,35,-1,-1,13,-1],
                [-1,-1,-1,-1,-1,-1],
                [-1,15,-1,-1,-1,-1]]
Output: 4
Explanation:
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.
*/

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int R = board.size();
        int C = board[0].size();
        int dest = R * C;
        queue<pair<int, int>> q;
        bool *visited = new bool[R*C + 1]{false};

        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            int index = q.front().first;
            int dist = q.front().second;
            q.pop();

            if (index == dest) {
                return dist;
            }

            for (int it = 1; it <= 6; it++) {
                int nextIndex = index + it;
                if (nextIndex > R*C) {
                    break;
                }

                // calculate row and col
                int row = (nextIndex - 1) / R; // this will give row from top
                row = R - 1 - row; // To get row from bottom

                int rightToLeft = (R - 1 - row) & 1;
                int col;

                if (rightToLeft) {
                    col = C - 1 - (nextIndex - 1) % C;
                }
                else {
                    col = (nextIndex - 1) % C;
                }

                // push in queue if not visited
                int boardIndex = board[row][col] == -1 ? nextIndex : board[row][col];
                if (!visited[boardIndex]) {
                    q.push({boardIndex, dist + 1});
                    visited[boardIndex] = true;
                }

            }
        }

        return -1;
    }
};
