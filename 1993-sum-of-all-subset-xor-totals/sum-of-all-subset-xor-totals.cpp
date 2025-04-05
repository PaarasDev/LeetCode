class Solution {
public:
     int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }

private:
    int dfs(vector<int>& nums, int index, int currentXor) {
        if (index == nums.size()) {
            return currentXor;
        }

        int withCurrent = dfs(nums, index + 1, currentXor ^ nums[index]);
        
        int withoutCurrent = dfs(nums, index + 1, currentXor);
        
        return withCurrent + withoutCurrent;
    }
};