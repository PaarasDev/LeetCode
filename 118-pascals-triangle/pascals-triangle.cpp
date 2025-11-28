class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);

        for (int i = 1; i <= numRows; i++) {
            ans[i-1].resize(i);
            long long val = 1;
            
            for (int j = 1; j <= i; j++) {
                ans[i-1][j-1] = val;
                val = val * (i - j) / j;
            }
        }

        return ans;
    }
};
