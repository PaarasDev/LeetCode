class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int row = m - 1, col = 0, cnt = 0;

        while (row >= 0 && col < n) {
            if (grid[row][col] < 0) {
                cnt += (n - col);
                row--;
            } else {
                col++;
            }
        }
        return cnt;
    }
};
