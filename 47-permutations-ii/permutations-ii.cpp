   class Solution {
public:
    void solve(int x, vector<int>& nums, set<vector<int>>& res) {
        int n = nums.size();
        if (x == n) {
            res.insert(nums);
            return;
        }
        for (int i = x; i < n; i++) {
            swap(nums[i], nums[x]);
            solve(x + 1, nums, res);
            swap(nums[i], nums[x]); 
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        solve(0, nums, res);
        vector<vector<int>> x(res.begin(),res.end());
        return x;
    }
};

        
  