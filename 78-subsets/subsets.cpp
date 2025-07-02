class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int>& list, vector<vector<int>>& ans) {
        if (i == nums.size()) {
            ans.push_back(list);
            return;
        }

        // Include nums[i]
        list.push_back(nums[i]);
        solve(i + 1, nums, list, ans);

        // Exclude nums[i]
        list.pop_back();
        solve(i + 1, nums, list, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> list;
        vector<vector<int>> ans;
        solve(0, nums, list, ans);
        return ans;
    }
};
