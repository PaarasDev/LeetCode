class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        // Check only tops[0] and bottoms[0] as possible candidates
        int ans = check(tops[0], tops, bottoms, n);
        if (ans != -1) return ans;
        return check(bottoms[0], tops, bottoms, n);
    }
    
    int check(int target, vector<int>& tops, vector<int>& bottoms, int n) {
        int rotations_top = 0, rotations_bottom = 0;
        for (int i = 0; i < n; ++i) {
            if (tops[i] != target && bottoms[i] != target) {
                return -1;  // impossible
            } else if (tops[i] != target) {
                rotations_top++;
            } else if (bottoms[i] != target) {
                rotations_bottom++;
            }
        }
        return min(rotations_top, rotations_bottom);
    }
};
