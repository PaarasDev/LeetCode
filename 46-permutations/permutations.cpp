class Solution {
public:
    void solve(int x, vector<int>& nums, vector<vector<int>>& res) {
        int n = nums.size();
        if (x == n) {
            res.push_back(nums);
            return;
        }
        for (int i = x; i < n; i++) {
            swap(nums[i], nums[x]);
            solve(x + 1, nums, res);
            swap(nums[i], nums[x]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(0, nums, res);
        return res;
    }
};
