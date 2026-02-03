class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        // First increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        if (i == 0 || i == n - 1) return false;

        // Decreasing
        int p = i;
        while (i + 1 < n && nums[i] > nums[i + 1]) i++;
        if (i == p || i == n - 1) return false;

        // Second increasing
        int q = i;
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;

        return i == n - 1;
    }
};
