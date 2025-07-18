class Solution {
public:
    void solve(int i, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (i == candidates.size() || target < 0) return;

        current.push_back(candidates[i]);
        solve(i, candidates, target - candidates[i], current, result);
        current.pop_back();

        solve(i + 1, candidates, target, current, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        solve(0, candidates, target, current, result);
        return result;
    }
};
