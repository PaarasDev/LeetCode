class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        // Map 1-based index to board coordinates (row, col)
        vector<pair<int, int>> cells(n * n + 1);
        bool leftToRight = true;
        int label = 1;
        for (int r = n - 1; r >= 0; --r) {
            if (leftToRight) {
                for (int c = 0; c < n; ++c) {
                    cells[label++] = {r, c};
                }
            } else {
                for (int c = n - 1; c >= 0; --c) {
                    cells[label++] = {r, c};
                }
            }
            leftToRight = !leftToRight;
        }

        vector<bool> visited(n * n + 1, false);
        queue<pair<int, int>> q; // (square, moves)
        q.push({1, 0});
        visited[1] = true;

        while (!q.empty()) {
            auto [square, moves] = q.front();
            q.pop();

            if (square == n * n) return moves;

            for (int next = square + 1; next <= min(square + 6, n * n); ++next) {
                auto [r, c] = cells[next];
                int destination = (board[r][c] == -1) ? next : board[r][c];
                if (!visited[destination]) {
                    visited[destination] = true;
                    q.push({destination, moves + 1});
                }
            }
        }
        return -1; // Cannot reach the end
    }
};
