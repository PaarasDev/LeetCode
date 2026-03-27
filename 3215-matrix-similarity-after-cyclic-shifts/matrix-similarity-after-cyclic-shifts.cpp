class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k %= n;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                int expected;

                if(i % 2 == 0) {
                    expected = mat[i][(j + k) % n];
                } else {
                    expected = mat[i][(j - k + n) % n];
                }

                if(mat[i][j] != expected)
                    return false;
            }
        }

        return true;
    }
};